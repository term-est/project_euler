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
std::size_t largest_palindrome_product(std::size_t upper_limit) noexcept;

[[nodiscard]] [[gnu::pure]]
std::size_t highly_composite_number() noexcept;

[[nodiscard]] [[gnu::pure]]
std::size_t sum_square_difference(std::size_t number) noexcept;

[[nodiscard]] [[gnu::pure]]
std::size_t nth_prime(std::size_t n) noexcept;

[[nodiscard]] [[gnu::pure]]
std::size_t sum_of_primes(std::size_t n) noexcept;

[[nodiscard]] [[gnu::pure]]
std::size_t pythagoras_triple(std::size_t upper_limit) noexcept;

[[nodiscard]] [[gnu::pure]]
std::size_t largest_product(std::string_view str, std::size_t window) noexcept;

} // end of namespace project_euler

