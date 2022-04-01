#include <cstddef>
#include <string>

namespace project_euler
{

// if input is 15, the output string will be 51, but since we are using this to check for palindromes
// it doesn't really matter
static std::string to_string(std::size_t input)
{
	std::string output;

	while (input > 0)
	{
		output.push_back('0' + (input % 10));
		input = input / 10;
	}

	return output;
}

// NOTE: am i a clown for passing a const ref to a string_view?
static bool is_palindrome(const std::string_view &input) noexcept
{
	for (int i = 0; i < input.size() / 2; ++i)
	{
		if (input[i] != input[input.size() - 1 - i])
			return false;
	}

	return true;
}

[[nodiscard]] [[gnu::pure]]
std::size_t largest_palindrome_product() noexcept
{
	std::size_t max_product = 0;

	for (std::uint16_t i = 999; i > 1; --i)
	{
		for (std::uint16_t  j = 999; j > 1; --j)
		{
			const std::size_t product = i * j;

			// early exit from the inner loop if possible
			if (product < max_product) [[likely]]
			{
				// if the condition is true, it's meaningless to try other i values
				if (i - 1 * 999 < max_product) [[unlikely]]
					return max_product;

				break;
			}

			if (is_palindrome(to_string(product))) [[unlikely]]
			   max_product = product;

		}
	}


	return max_product;
}

} // end of namespace project_euler