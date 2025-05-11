#include "Platform/OpenGL/OpenGLTexture.h"

#include <memory>

#include <glad/glad.h>
#include <stb_image/std_image.h>

#include "IO/VFS.h"
#include "IO/VFile.h"
#include "Utils/Log.h"

namespace aero3d {

OpenGLTexture::OpenGLTexture(std::string& path)
{
    glGenTextures(1, &m_TextureID);
    glBindTexture(GL_TEXTURE_2D, m_TextureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    std::shared_ptr<VFile> file = VFS::ReadFile(path);
    file->Load();

    int width, height, nrChannels;
    unsigned char* data = stbi_load_from_memory(static_cast<const stbi_uc*>(file->GetData()), file->GetLength(), &width, &height, &nrChannels, 0);

    if (data) {
        GLenum format = (nrChannels == 3) ? GL_RGB : GL_RGBA;

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        LogErr(ERROR_INFO, "Failed to load texture: %s", path);
    }

    file->Unload();
}

OpenGLTexture::~OpenGLTexture()
{
    glDeleteTextures(1, &m_TextureID);
}

void OpenGLTexture::Bind(unsigned int slot)
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_TextureID);
}

} // namespace aero3d