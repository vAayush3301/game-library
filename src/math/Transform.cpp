#include "library/math/transform.h"

namespace gamelib::math {
    Transform2D::Transform2D(float x, float y, float scaleX, float scaleY, float rotationDeg) : m_Position{x, y},
        m_Scale{scaleX, scaleY}, m_Rotation(rotationDeg), m_ModelMatrix(), m_Dirty(true) {
    }

    void Transform2D::SetPosition(float x, float y) {
        m_Position = {x, y};
        m_Dirty = true;
    }

    void Transform2D::SetScale(float x, float y) {
        m_Scale = {x, y};
        m_Dirty = true;
    }

    void Transform2D::SetRotation(float degrees) {
        m_Rotation = degrees;
        m_Dirty = true;
    }

    const Mat4 &Transform2D::GetMatrix() {
        if (m_Dirty) {
            Recalculate();
        }
        return m_ModelMatrix;
    }

    void Transform2D::Recalculate() {
        Mat4 translation = Mat4::translation(m_Position.x, m_Position.y, 0.0f);
        Mat4 rotation = Mat4::rotationZ(m_Rotation);
        Mat4 scale = Mat4::scale(m_Scale.x, m_Scale.y, 1.0f);

        m_ModelMatrix = translation * rotation * scale;
        m_Dirty = false;
    }
}