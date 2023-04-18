
#include "TransformableStruct.hpp"

namespace Transformable {
    class ITransformable {
        public:
            virtual ~ITransformable() = default;
            virtual Point3f getPos() = 0;
            virtual Point3f getAxis() = 0;
            virtual void setPos(Point3f) = 0;
            virtual void setAxis(Point3f) = 0;
            virtual TransformableType getType() = 0;
    };
}