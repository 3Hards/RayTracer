#include "IVector.hpp"
#include "ATransformable.hpp"

namespace RayTracer {
    class Vector : public IVector, public Transformable::ATransformable {
        public:
            void setPrimitives(std::vector<std::shared_ptr<Transformable::IPrimitive>>);
            std::tuple<bool, Material::IMaterial, Transformable::Point3f> run(Transformable::ILight);
        private:
            std::vector<std::shared_ptr<Transformable::IPrimitive>> _primitives;
    };
}