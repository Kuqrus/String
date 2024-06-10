#include "String.h"

String::String() : m_Size(0), m_Capacity(2)
{
    m_String = new char[m_Capacity];
    m_String[0] = '\0';
}
String::String(const char& c) : m_Size(1), m_Capacity(2)
{
    m_String = new char[m_Capacity];
    m_String[0] = c;
    m_String[m_Size] = '\0';
}
String::String(const char* chars) : m_Size(strlen(chars))
{
    if (m_Size == 0)
    {
        m_Capacity = 2;
        m_String = new char[m_Capacity];
        m_String[m_Size] = '\0';
    }
    else
    {
        m_Capacity = m_Size * 3 / 2;
        if (m_Capacity == 1)
            m_Capacity++;
        m_String = new char[m_Capacity];
        memcpy(m_String, chars, m_Size + 1);
    }
}
String::String(const String& str) : m_Size(str.m_Size), m_Capacity(str.m_Capacity)
{
    if (this == &str)
        return;
    m_String = new char[m_Capacity];
    memcpy(m_String, str.m_String, m_Size + 1);
}
String::String(String&& str) noexcept : m_Size(str.m_Size), m_Capacity(str.m_Capacity), m_String(str.m_String)
{
    if (this == &str)
        return;
    str.m_Size = 0;
    str.m_Capacity = 0;
    str.m_String = nullptr;
}

String::~String()
{
    delete[] m_String;
}

const String& String::operator += (const String& rhs)
{
    while (IsFull() || m_Size + rhs.m_Size >= m_Capacity)
        UpdateStringSize();

    strcat_s(m_String, m_Capacity, rhs.m_String);
    m_Size += rhs.m_Size;
    m_String[m_Size] = '\0';

    return *this;
}
const String& String::operator += (const char* rhs)
{
    while (IsFull() || m_Size + strlen(rhs) >= m_Capacity)
        UpdateStringSize();

    strcat_s(m_String, m_Capacity, rhs);
    m_Size += strlen(rhs);
    m_String[m_Size] = '\0';

    return *this;
}
const String& String::operator += (const char rhs)
{
    if (IsFull() || m_Size + 1 >= m_Capacity)
        UpdateStringSize();

    m_String[m_Size] = rhs;
    m_Size += 1;
    m_String[m_Size] = '\0';

    return *this;
}

const String operator + (const String& lhs, const String& rhs)
{
    return String(lhs) += rhs;
}
const String operator + (const String& lhs, const char* rhs)
{
    return String(lhs) += rhs;
}
const String operator + (const String& lhs, const char rhs)
{
    return String(lhs) += rhs;
}

const String& String::operator = (const String& rhs)
{
    if (this == &rhs)
        return *this;

    m_Size = rhs.m_Size;
    m_Capacity = rhs.m_Capacity;

    delete[] m_String;
    m_String = new char[m_Capacity];
    memcpy(m_String, rhs.m_String, m_Size + 1);

    return *this;
}
const String& String::operator = (String&& rhs) noexcept
{
    if (this == &rhs)
        return *this;

    m_Size = rhs.m_Size;
    m_Capacity = rhs.m_Capacity;
    m_String = rhs.m_String;

    rhs.m_Size = 0;
    rhs.m_Capacity = 0;
    rhs.m_String = nullptr;

    return *this;
}
const String& String::operator = (const char* rhs)
{
    m_Size = strlen(rhs);
    m_Capacity = m_Size * 3 / 2;

    delete[] m_String;
    m_String = new char[m_Capacity];
    memcpy(m_String, rhs, m_Size);
    m_String[m_Size] = '\0';

    return *this;
}
const String& String::operator = (const char rhs)
{
    m_Size = 1;
    m_Capacity = 2;

    delete[] m_String;
    m_String = new char[m_Capacity];
    m_String[0] = rhs;
    m_String[m_Size] = '\0';

    return *this;
}


std::ostream& operator << (std::ostream& os, const String& rhs)
{
    for (size_t i = 0; i < rhs.m_Size; i++)
    {
        os << rhs.m_String[i];
    }
    return os;
}

void String::UpdateStringSize()
{
    char* temp = new char[m_Capacity];
    memcpy(temp, m_String, m_Size + 1);

    m_Capacity = m_Capacity * 3 / 2;
    delete[] m_String;

    m_String = new char[m_Capacity];
    memcpy(m_String, temp, m_Size + 1);

    delete[] temp;
}