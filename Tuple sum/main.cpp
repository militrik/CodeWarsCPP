#include <iostream>
#include <tuple>
#include <type_traits>

// Helper function to check if a type is numeric
template <typename T>
struct is_numeric {
    static const bool value = std::is_arithmetic<T>::value;
};

// Base case for the recursion, when the tuple is empty
template <size_t Index, typename... Args>
typename std::enable_if<Index == sizeof...(Args), double>::type
add_numeric_elements(const std::tuple<Args...>& t) {
    return 0.0;
}

// Recursive case, where we check and add the numeric elements
template <size_t Index, typename... Args>
typename std::enable_if<Index < sizeof...(Args), double>::type
add_numeric_elements(const std::tuple<Args...>& t) {
    const auto& element = std::get<Index>(t);
    double sum = is_numeric<decltype(element)>::value ? element : 0.0;
    return sum + add_numeric_elements<Index + 1>(t);
}

// Wrapper function to call the recursive function
template <typename... Args>
double add_numeric_elements(const std::tuple<Args...>& t) {
    return add_numeric_elements<0>(t);
}

int main() {
    std::tuple<int, double, char, float> myTuple(5, 3.14, 'a', 2.0f);
    double result = add_numeric_elements(myTuple);
    std::cout << "Sum of numeric elements: " << result << std::endl;

    return 0;
}
