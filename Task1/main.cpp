#include <iostream>
#include <string>
#include <unordered_map>

std::string SimpleConvertString(const std::string &original) {
    // Normalize
    std::string normalize;
    std::transform(std::begin(original), std::end(original), std::back_inserter(normalize), ::toupper);

    // Convert
    std::string result;
    std::transform(std::begin(normalize), std::end(normalize), std::back_inserter(result), [&normalize](auto item) {
        return std::count(std::begin(normalize), std::end(normalize), item) > 1 ? ')' : '(';
    });

    return result;
}

std::string OptimizedConvertString(const std::string &original) {
    // Normalize
    std::unordered_map<char, int> normalizeCache;
    for (const auto               item: original) { normalizeCache[(char) std::toupper(item)]++; }

    // Convert
    std::string result;
    std::transform(std::begin(original), std::end(original), std::back_inserter(result), [&normalizeCache](auto item) {
        return normalizeCache[(char) std::toupper(item)] > 1 ? ')' : '(';
    });

    return result;
}

int main() {
    const auto original = "Success";
    std::cout << "Original:\t" << original << std::endl;

    const auto simple = SimpleConvertString(original);
    std::cout << "Converted(Simple):\t" << simple << std::endl;

    const auto optimized = OptimizedConvertString(original);
    std::cout << "Converted(Optimized):\t" << optimized << std::endl;

    return 0;
}
