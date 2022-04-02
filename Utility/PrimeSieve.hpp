#include <bitset>
#include <memory>
#include <cmath>


namespace project_euler
{


namespace
{

template <std::size_t SieveSize>
concept StackAllocatable =  SieveSize < 4'000'000;

template <std::size_t SieveSize, bool = StackAllocatable<SieveSize>>
class PrimeSieveBase;

template <std::size_t SieveSize>
class PrimeSieveBase<SieveSize, true>
{
protected:

	std::bitset<SieveSize> m_sieve;
	std::bitset<SieveSize>* const m_sieve_ptr = &m_sieve;

};

template <std::size_t SieveSize>
class PrimeSieveBase<SieveSize, false>
{
protected:

	std::unique_ptr<std::bitset<SieveSize>> m_sieve_ptr;
	// const std::bitset<SieveSize>& m_sieve;

	PrimeSieveBase() : m_sieve_ptr{std::make_unique<std::bitset<SieveSize>>()}
	{}

	//~PrimeSieveBase()
	//{
	//	delete m_sieve_ptr;
	//}

};


} // end of anonymous namespace


enum isComposite : bool
{
	PRIME = false,
	COMPOSITE = true
};

template <std::size_t SieveSize>
class PrimeSieve : PrimeSieveBase<SieveSize>
{

	using enum isComposite;

	std::bitset<SieveSize>& sieve = *PrimeSieveBase<SieveSize>::m_sieve_ptr;

//using PrimeSieveBase<SieveSize>;

public:

	constexpr void populate()
	{
		sieve[0] = sieve[1] = COMPOSITE;
		sieve[2] = PRIME;

		const std::size_t upper_limit = std::ceil(std::sqrt(SieveSize));
		for (std::size_t i = 2; i <= upper_limit; ++i)
		{
			if (sieve[i] != PRIME) [[likely]]
				continue;

			// set all composites to true
			for (std::size_t j = i * 2; j < SieveSize; j += i)
				sieve[j] = COMPOSITE;
		}
	}

	constexpr const std::bitset<SieveSize>& get_sieve() const
	{
		return sieve;
	}

};

} // end of namespace project_euler


