#pragma once

namespace project_euler
{

[[nodiscard]] [[gnu::pure]]
size_t sum_of_multiples(std::size_t begin, std::size_t end, const std::array<std::size_t, 2>& multipliers) noexcept;

[[nodiscard]] [[gnu::pure]]
std::size_t sum_even_fibonacci_numbers(std::size_t threshold) noexcept;

// NOTE: function signature/function ptr for functions with default args?
[[nodiscard]] [[gnu::pure]]
std::size_t largest_prime_factor(std::size_t number = 600851475143) noexcept;

[[nodiscard]] [[gnu::pure]]
std::size_t largest_palindrome_product() noexcept;

[[nodiscard]] [[gnu::pure]]
std::size_t highly_composite_number() noexcept;

} // end of namespace project_euler

