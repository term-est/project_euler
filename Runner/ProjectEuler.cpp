#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/chrono.h>

#include "Solutions.hpp"

#include <chrono>

#pragma GCC push_options
#pragma GCC optimize ("O0")

template <typename T, typename ... Args>
auto benchmark(T func, Args ... args)
{
	constexpr std::size_t iter = 100'000;

	std::chrono::high_resolution_clock::time_point timer = std::chrono::high_resolution_clock::now();

	size_t average_time = 0;

	for (size_t i = 0; i < iter; ++i)
		func(std::forward<Args>(args) ...);


	average_time = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - timer).count();

	fmt::print(fmt::fg(fmt::color::gold), "Elapsed time: {:d} microseconds\n", average_time / iter);

	return func(std::forward<Args>(args) ...);
}
#pragma GCC pop_options


auto main() -> int
{
	using namespace project_euler;

	fmt::print("Project Setup Has Been Completed Successfully\n");

	fmt::print("Problem 1: {}\n", sum_of_multiples(0, 1000, {3, 5}));

	fmt::print("Problem 2: {}\n", sum_even_fibonacci_numbers(4'000'000));

	fmt::print("Problem 3: {}\n", largest_prime_factor(600851475143));

	fmt::print("Problem 4: {}\n", largest_palindrome_product());

	fmt::print("Problem 5: {}\n", highly_composite_number());

	benchmark(largest_palindrome_product);

	return 0;
}
