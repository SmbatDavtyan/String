#include "string.h"
#include <string>
#include <cstring>

String::String()
{
    m_str = nullptr;
    m_size = 0;
}

String::String(const char* str)
{
    m_size = len(str);
    m_str = new char[m_size + 1];
    m_str[m_size] = '\0';

    for (int i = 0; i < m_size; ++i)
    {
        m_str[i] = str[i];
    }
}

String::String(const String& str)
{
    m_size = str.m_size;
    m_str = new char[m_size + 1];
    m_str[m_size] = '\0';

    for (int i = 0; i < m_size; ++i)
    {
        m_str[i] = str.m_str[i];
    }
}

String::~String()
{
    delete[] m_str;
}

bool String::is_empty() const
{
    return m_size == 0;
}

int String::

(const char* str) const
{
    if(is_empty()){
    return 0; 
    }
    int count = 0;
    while (str[count++] != '\0') {}

    return count - 1;
}

void String::append(const String& str)
{
    if(is_empty()){
    return; 
    }
    char* temp_str = new char[m_size + str.m_size + 1];

    int i, j = 0;

    for (i = 0; i < m_size; ++i)
    {
        temp_str[i] = m_str[i];
    }

    for (i = m_size; i < m_size + str.m_size; ++i)
    {
        temp_str[i] = str.m_str[j++];
    }

    m_size = m_size + str.m_size;

    temp_str[m_size] = '\0';

    delete[] m_str;

    m_str = temp_str;
}

const String& String::operator=(const String& str)
{
    m_size = str.m_size;
    delete[] m_str;

    m_str = new char[m_size + 1];
    m_str[m_size] = '\0';

    for (int i = 0; i < m_size; ++i)
    {
        m_str[i] = str.m_str[i];
    }
    return *this;
}

String String::operator+(const String& str) const
{
    String result;

    result.m_size = m_size + str.m_size;

    result.m_str = new char[result.m_size + 1];

    result.m_str[result.m_size] = '\0';

    int i;

    for (i = 0; i < m_size; ++i)
    {
        result.m_str[i] = m_str[i];
    }

    int j = 0;

    for (i = m_size; i < result.m_size; ++i)
    {
        result.m_str[i] = str.m_str[j++];
    }

    return result;
}

const String& String::operator+=(const String& str)
{
    *this = *this + str;

    return *this;
}

bool String::operator<(const String& str) const
{
    return strcmp(m_str, str.m_str) == -1;
}

char& String::operator[](int index)
{
    assert(m_ptr == nullptr || is_empty() || index < 0 || index >= m_size);
    return m_str[index];
}

const char& String::operator[](int index) const
{
    assert(m_ptr == nullptr || is_empty() || index < 0 || index >= m_size);
    return m_str[index];
}

void String::swap(String& str)
{
    String temp = *this;

    *this = str;

    str = temp;
}
// dz
// barev dzez

int String::find_first_of(const char* str)
{
    int str_len = len(str);
    int res_index = -1;
   
    for (int i = 0; i < m_size; ++i)
    {
        for (int j = 0; j < str_len; ++j)
        {
            if ((i + j < m_size) && (m_str[i + j] != str[j]))
            {
                break;
            }
        }
        
        if (j == str_len)
        {
            return i;
        }
    }
    return -1;
}

std::ostream & operator<<(std::ostream& out, const String& str)
{
    for (int i = 0; i < str.m_size; ++i)
    {
        out << str.m_str[i];
    }
    return out;
}

