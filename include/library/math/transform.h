#pragma once
#include "library/math/vec2.h"
#include "library/math/mat4.h"

namespace gamelib::math {
    class Transform2D {
    public:
        Transform2D();
        Transform2D(float x, float y, float scaleX, float scaleY, float rotationDeg = 0.0f);

        void SetPosition(float x, float y);
        void SetScale(float x, float y);
        void SetRotation(float degrees);

        const Mat4& GetMatrix();

    private:
        void Recalculate();

        Vec2 m_Position = {0.0f, 0.0f};
        Vec2 m_Scale = {1.0f, 1.0f};
        float m_Rotation = 0.0f;

        Mat4 m_ModelMatrix;
        bool m_Dirty = true;
    };
}