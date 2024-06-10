#pragma once
#include "inc.h"

class String
{
public:
    String();
    explicit String(const char& c);
    String(const char* chars);
    String(const String& str);
    String(String&& str) noexcept;

    virtual ~String();


    String(int i) = delete;
    const String& operator += (int rhs) = delete;
    const friend String operator + (String lhs, int rhs) = delete;
    const String& operator = (int rhs) = delete;


    const String& operator += (const String& rhs);
    const String& operator += (const char* rhs);
    const String& operator += (const char rhs);


    const friend String operator + (const String& lhs, const String& rhs);
    const friend String operator + (const String& lhs, const char* rhs);
    const friend String operator + (const String& lhs, const char rhs);


    const String& operator = (const String& rhs);
    const String& operator = (String&& rhs) noexcept;
    const String& operator = (const char* rhs);
    const String& operator = (const char rhs);


    friend std::ostream& operator << (std::ostream& os, const String& rhs);


    size_t GetSize() const { return m_Size; }
    char* GetString() const { return m_String; }


private:
    size_t m_Size = 0;
    size_t m_Capacity = 0;

    char* m_String = nullptr;


private:
    bool IsFull() const { return m_Size == m_Capacity; }
    void UpdateStringSize();
};