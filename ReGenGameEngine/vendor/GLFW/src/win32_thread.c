INDX( 	 ��@r           (   8   �         �//)ond                         A�    �w���l�w���l�w���l�w��� �       �              	v c 1 4 0 . p d b                   L�    h T     A�    �w���l�w���l�w���l�w��� �       �              	v c 1 4 0 . p d b                   h T     A�    �w���l�w���l�w���l�w��� �       �              	v c 1 4 0 . p d b                   h T     A�    �w���l�w���l�w���l�w��� �       �              	v c 1 4 0 . p d b                  A�    �w���l�w���l�w���l�w��� �       �              	v c 1 4 0 . p d b                   J       L�    h T     A�    �w���l�w���l�w���l�w��� �       �              	v c 1 4 0 . p d b                   h T     A�    �w���l�w���l�w���l�w��� �       �              	v c 1 4 0 . p d b                   h T     A�    �w���l�w���l�w���l�w��� �       �              	v c 1 4 0 . p d b                   A�    �w���l�w���l�w���l�w��  �       �              	v c 1 4 0 . p d b                   A�    �w���l�w���l�w���l�w��� �       �              	v c 1 4 0 . p d b                   A�    �w���l�w���l�w���l�w��� �       �              	v c 1 4 0 . p d b                   #include <assert.h>


//////////////////////////////////////////////////////////////////////////
//////                       GLFW platform API                      //////
///////////////////////////////////////////////////////////// ///////////

GLFWbool _glfwPlatformCreateTls(_GLFWtls* tls)
{
    assert(tls->win32.allocated == GLFW_FALSE);

    tls->win32.index = TlsAlloc();
    if (tls->win32.index == TLS_OUT_OF_INDEXES)
    {
        _glfwInputErrorWin32(GLFW_PLATFORM_ERROR,
                             "Win32: Failed to allocate TLS index");
        return GLFW_FALSE;
    }

    tls->win32.allocated = GLFW_TRUE;
    return GLFW_TRUE;
}

void _glfwPlatformDestroyTls(_GLFWtls* tls)
{
    if (tls->win32.allocated 
        TlsFree(tls->win32.index);
    memset(tls, 0, sizeof(_GLFWtls));
}

void* _glfwPlatformGetTls(_GLFWtls* tls)
{
    assert(tls->win32.allocated == GLFW_TRUE);
    return TlsGetValue(tls->win32.index);
}

void _glfwPlatformSetTls(_GLFWtls* tls, void* value)
{
    assert(tls->win32.allocated == GLFW_TRUE);
    TlsSetValue(tls->win32.index, value);
}

GLFWbool _glfwPlatformCreateMutex(_GLFWmutex* mutex)
{
    assert(mutex->win32.allocated == GLFW_FALSE);
    InitializeCriticalSecti (&mutex->win32.section);
    return mutex->win32.allocated = GLFW_TRUE;
}

void _glfwPlatformDestroyMutex(_GLFWmutex* mutex)
{
    if (mutex->win32.allocated)
        DeleteCriticalSection(&mutex->win32.section);
    memset(mutex, 0, sizeof(_GLFWmutex));
}

void _glfwPlatformLockMutex(_GLFWmutex* mutex)
{
    assert(mutex->win32.allocated == GLFW_TRUE);
    EnterCriticalSection(&mutex->win32.section);
}

void _glfwPlatformUnlockMutex(_GLFWmutex* mutex)
{
    assert(mutex->win32.allocate == GLFW_TRUE);
    LeaveCriticalSection(&mutex->win32.section);
}

