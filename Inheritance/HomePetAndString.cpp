#include <iostream>
#include <vector>

class Pet {
protected:
    std::string name;
public:
    Pet(const std::string& n) : name(n) {}
    virtual void show() const = 0;
    virtual ~Pet() {}
};

class Dog : public Pet {
    std::string breed;
    int age;
public:
    Dog(const std::string& n, const std::string& b, int a) : Pet(n), breed(b), age(a) {}
    void show() const override {
        std::cout << "Dog: " << name << ", breed: " << breed << ", age: " << age << std::endl;
    }
};

class Cat : public Pet {
    std::string color;
    bool isIndoor;
public:
    Cat(const std::string& n, const std::string& c, bool indoor) : Pet(n), color(c), isIndoor(indoor) {}
    void show() const override {
        std::cout << "Cat: " << name << ", color: " << color
            << ", " << (isIndoor ? "indoor" : "outdoor") << std::endl;
    }
};

class Parrot : public Pet {
    std::string species;
    bool canTalk;
public:
    Parrot(const std::string& n, const std::string& s, bool talk) : Pet(n), species(s), canTalk(talk) {}
    void show() const override {
        std::cout << "Parrot: " << name << ", species: " << species
            << ", " << (canTalk ? "can talk" : "can't talk") << std::endl;
    }
};

class String {
protected:
    char* data;
    size_t len;
public:
    String() : data(nullptr), len(0) {}

    String(const char* s) {
        if (!s) {
            data = nullptr;
            len = 0;
            return;
        }
        len = 0;
        while (s[len] != '\0') ++len;
        data = new char[len + 1];
        for (size_t i = 0; i < len; ++i)
            data[i] = s[i];
        data[len] = '\0';
    }

    String(const String& other) {
        len = other.len;
        if (len) {
            data = new char[len + 1];
            for (size_t i = 0; i < len; ++i)
                data[i] = other.data[i];
            data[len] = '\0';
        }
        else {
            data = nullptr;
        }
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            len = other.len;
            if (len) {
                data = new char[len + 1];
                for (size_t i = 0; i < len; ++i)
                    data[i] = other.data[i];
                data[len] = '\0';
            }
            else {
                data = nullptr;
            }
        }
        return *this;
    }

    size_t length() const { return len; }

    void clear() {
        delete[] data;
        data = nullptr;
        len = 0;
    }

    ~String() {
        delete[] data;
    }

    String operator+(const String& other) const {
        String res;
        res.len = len + other.len;
        res.data = new char[res.len + 1];
        for (size_t i = 0; i < len; ++i)
            res.data[i] = data[i];
        for (size_t i = 0; i < other.len; ++i)
            res.data[len + i] = other.data[i];
        res.data[res.len] = '\0';
        return res;
    }

    String& operator+=(const String& other) {
        *this = *this + other;
        return *this;
    }

    bool operator==(const String& other) const {
        if (len != other.len)
            return false;
        for (size_t i = 0; i < len; ++i)
            if (data[i] != other.data[i])
                return false;
        return true;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const String& s) {
        if (s.data)
            for (size_t i = 0; i < s.len; ++i)
                os << s.data[i];
        return os;
    }
};

class BitString : public String {
    static bool isValid(const char* s) {
        if (!s) return true;
        for (size_t i = 0; s[i]; ++i)
            if (s[i] != '0' && s[i] != '1')
                return false;
        return true;
    }

    int toInt() const {
        if (!data || len == 0) return 0;
        int res = 0;
        bool negative = (data[0] == '1');
        for (size_t i = 0; i < len; ++i)
            res = (res << 1) | (data[i] - '0');
        if (negative) res -= (1 << len);
        return res;
    }
    void fromInt(int value, size_t bits) {
        clear();
        if (bits == 0) bits = 1;
        data = new char[bits + 1];
        unsigned int val = static_cast<unsigned int>(value);
        for (int i = bits - 1; i >= 0; --i) {
            data[i] = ((val & 1) ? '1' : '0');
            val >>= 1;
        }
        data[bits] = '\0';
        len = bits;
    }
public:
    BitString() : String() {}

    BitString(const char* s) : String() {
        if (isValid(s)) {
            len = 0;
            while (s[len] != '\0') ++len;
            data = new char[len + 1];
            for (size_t i = 0; i < len; ++i)
                data[i] = s[i];
            data[len] = '\0';
        }
        else {
            data = nullptr;
            len = 0;
        }
    }

    BitString(const BitString& other) : String(other) {}

    BitString& operator=(const BitString& other) {
        String::operator=(other);
        return *this;
    }

    void negate() {
        if (!data || len == 0) return;
        for (size_t i = 0; i < len; ++i)
            data[i] = (data[i] == '0') ? '1' : '0';
        for (int i = (int)len - 1; i >= 0; --i) {
            if (data[i] == '0') {
                data[i] = '1';
                break;
            }
            else {
                data[i] = '0';
            }
        }
    }

    BitString operator+(const BitString& other) const {
        int a = this->toInt();
        int b = other.toInt();
        int sum = a + b;
        size_t bits = (len > other.len ? len : other.len) + 1;
        BitString res;
        res.fromInt(sum, bits);
        return res;
    }

    BitString& operator+=(const BitString& other) {
        *this = *this + other;
        return *this;
    }

    bool operator==(const BitString& other) const {
        return String::operator==(other);
    }

    bool operator!=(const BitString& other) const {
        return String::operator!=(other);
    }
};


int main() {

    std::vector<Pet*> pets;
    pets.push_back(new Dog("Reks", "Labrador", 5));
    pets.push_back(new Cat("Murka", "black", true));
    pets.push_back(new Parrot("Kesha", "Ara", true));
    for (const auto& p : pets) p->show();
    for (auto& p : pets) delete p;


    String s1("Hello");
    String s2(" world");
    String s3 = s1 + s2;
    std::cout << "Concat: " << s3 << std::endl;
    std::cout << "Length: " << s3.length() << std::endl;
    s3.clear();
    std::cout << "After clear: '" << s3 << "'" << std::endl;

    String s4("test");
    String s5("test");
    String s6("best");
    std::cout << "s4==s5: " << (s4 == s5) << ", s4==s6: " << (s4 == s6) << std::endl;

    BitString b1("1011");
    BitString b2("0011");
    std::cout << "BitString b1: " << b1 << ", b2: " << b2 << std::endl;
    BitString b3 = b1 + b2;
    std::cout << "b1 + b2 = " << b3 << std::endl;
    b3.negate();
    std::cout << "Negate b3: " << b3 << std::endl;

    BitString b4("10a11");
    std::cout << "b4: '" << b4 << "'" << std::endl;

    return 0;
}