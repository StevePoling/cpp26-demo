// C++26 Demo - Key Highlights
// Compile with: g++ -std=c++26 -freflection (GCC 16+) or equivalent

#include <print>
#include <vector>
#include <cassert>

// 1. Contracts (pre/post/contract_assert)
int divide(int a, int b)
    pre(b != 0)                    // precondition
    post(r : r * b == a)           // postcondition (r = return value)
{
    contract_assert(a % b == 0);   // runtime-checked assertion in some modes
    return a / b;
}

// 2. Placeholder variables with no name (_)
void process(const std::vector<int>& data) {
    for (auto [_, value] : data | std::views::enumerate) {  // ignore index
        std::print("value: {}\n", value);
    }
}

// 3. Pack indexing (super clean!)
template<typename... Ts>
void print_nth(size_t n, Ts... args) {
    std::print("The {}th argument is: {}\n", n, args...[n]);  // pack...[N]
}

// 4. #embed (embed binary data at compile time)
constexpr unsigned char icon_data[] = {
    #embed "icon.png"   // or any file - bytes are baked in
};

// 5. Reflection teaser (very powerful new capability)
#if __has_feature(reflection) || defined(__cpp_reflection)
import std::meta;  // or <meta> depending on implementation

consteval auto get_type_name() {
    return std::meta::name_of(^int);  // ^^int or ^Type syntax
}
#endif

int main() {
    std::print("C++26 Demo\n\n");

    // Contracts
    std::print("divide(10, 2) = {}\n", divide(10, 2));

    // Placeholder + structured bindings
    process({10, 20, 30});

    // Pack indexing
    print_nth(1, "hello", 42, 3.14, "world");

    std::print("Embedded data size: {} bytes\n", sizeof(icon_data));

#if __has_feature(reflection)
    std::print("Reflection: type name of int is {}\n", get_type_name());
#endif

    return 0;
}
