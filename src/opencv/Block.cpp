#include "Block.h"
sBlock::sBlock()
{
	m_x = 0;
	m_y = 0;
	m_a = 0;
	m_b = 0;
}
sBlock::~sBlock() { ; }
sBlock::sBlock
(
	unsigned int costruct_m_x,
	unsigned int costruct_m_y,
	unsigned int costruct_m_a,
	unsigned int costruct_m_b
)
{
	m_x = costruct_m_x;
	m_y = costruct_m_y;
	m_a = costruct_m_a;
	m_b = costruct_m_b;
}