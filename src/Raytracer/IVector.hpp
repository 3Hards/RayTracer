
#include <vector>
#include <memory>
#include "ITransformable.hpp"

namespace Transformable {
    class IPrimitive;
    class ILight;
}
namespace Material {
    class IMaterial;
}

namespace RayTracer {
    class IVector : public Transformable::ITransformable {
        public:
            virtual void setPrimitives(std::vector<std::shared_ptr<Transformable::IPrimitive>>) = 0;
            virtual std::tuple<bool, Material::IMaterial, Transformable::Point3f> run(Transformable::ILight) = 0;
    };
}
