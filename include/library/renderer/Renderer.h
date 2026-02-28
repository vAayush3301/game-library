class Renderer {
public:
    void Clear() const;
    void Draw(const VertexArray& va, const Shader& shader) const;
};