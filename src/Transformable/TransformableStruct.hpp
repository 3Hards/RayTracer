namespace Transformable {

    enum class TransformableType {
        Light,
        Primitive,
        Camera
    };

    struct Point3f {
        public:
            float x;
            float y;
            float z;
    };
}