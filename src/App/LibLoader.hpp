/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LibLoader
*/

#pragma once
#include <exception>
#include <functional>
#include <memory>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <dlfcn.h>
#endif

namespace App {
    template <typename ReturnType, typename... ArgsType>
    class LibLoader
    {
        public:
            ~LibLoader()
            {
                closeLibs();
            }

            LibLoader(const LibLoader &) = delete;
            LibLoader &operator=(const LibLoader &) = delete;

            static LibLoader &getInstance()
            {
                static LibLoader _instance;
                return _instance;
            }

            bool isLibOpen(const std::string &libPath) const
            {
                for (const auto &lib : _libs) {
                    if (lib.first == libPath && lib.second != nullptr) {
                        return true;
                    }
                }
                return false;
            }

            void closeLib(std::string &libPath)
            {
                for (auto it = _libs.begin(); it != _libs.end(); ++it) {
                    if (it->first == libPath) {
                        if (it->second != nullptr) {
                            #ifdef _WIN32
                                FreeLibrary(it->second);
                            #else
                                dlclose(it->second);
                            #endif
                        }
                        it->second = nullptr;
                        it = _libs.erase(it);
                        break;
                    }
                }
            }

            /**
             * @brief Get the Symbol object
             *
             * @param symbol the name of the symbol
             * @param libPath the path to the library
             * @return std::unique_ptr<std::function<T>>
             */

            std::function<ReturnType(ArgsType...)> getSymbol(
            const std::string &symbol,
            const std::string &libPath)
            {
                #ifdef _WIN32
                    std::string extension = ".dll";
                #else
                    std::string extension = ".so";
                #endif
                if (isLibOpen(libPath + extension) == false) {
                    openLib(libPath);
                }
                auto handle = getHandle(libPath);
                if (!handle) {
                    #ifdef _WIN32
                        throw std::runtime_error("GetSymbol Error: " + std::to_string(GetLastError()));
                    #else
                        throw std::runtime_error("GetSymbol Error: " + std::string(dlerror()));
                    #endif
                }

                #ifdef _WIN32
                    FARPROC func = GetProcAddress(handle, symbol.c_str());
                #else
                    void *func = dlsym(handle, symbol.c_str());
                #endif

                if (!func) {
                    #ifdef _WIN32
                        throw std::runtime_error("FindSymbol Error: " + std::to_string(GetLastError()));
                    #else
                        throw std::runtime_error("FindSymbol Error: " + std::string(dlerror()));
                    #endif
                }
                return std::function<ReturnType(ArgsType...)>(reinterpret_cast<ReturnType (*)(ArgsType...)>(func));
            }

        private:

            void closeLibs()
            {
                for (auto &lib : _libs) {
                    if (lib.second != nullptr) {
                        #ifdef _WIN32
                            FreeLibrary(lib.second);
                        #else
                            dlclose(lib.second);
                        #endif
                    }
                    lib.second = nullptr;
                }
                _libs.clear();
            }

            #ifdef _WIN32
                HINSTANCE getHandle(const std::string &libPath) const
            #else
                void *getHandle(const std::string &libPath) const
            #endif
                {
                    for (const auto &lib : _libs) {
                        if (lib.first == libPath) {
                            return lib.second;
                        }
                    }
                    return nullptr;
                }

            LibLoader() = default;

            void openLib(const std::string &libPath)
            {
                #ifdef _WIN32
                    HINSTANCE handle = LoadLibrary(libPath.c_str());
                #else
                    void *handle = dlopen(libPath.c_str(), RTLD_LAZY);
                #endif
                if (!handle) {
                    #ifdef _WIN32
                        throw std::runtime_error("OpenLib Error: " + std::to_string(GetLastError()));
                    #else
                        throw std::runtime_error("OpenLib Error: " + std::string(dlerror()));
                    #endif
                }
                _libs.emplace_back(libPath, handle);
            }

            #ifdef _WIN32
                std::vector<std::pair<std::string, HINSTANCE>> _libs;
            #else
                std::vector<std::pair<std::string, void *>> _libs;
            #endif
    };
}
