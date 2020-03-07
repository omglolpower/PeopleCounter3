#pragma once
struct sBlock
{
private:

public:
	sBlock();
	~sBlock();
	sBlock
	(
		unsigned int costruct_m_x,
		unsigned int costruct_m_y,
		unsigned int costruct_m_a,
		unsigned int costruct_m_b
	);

	unsigned int m_x = 0;
	unsigned int m_y = 0;
	unsigned int m_a = 0;
	unsigned int m_b = 0;
};