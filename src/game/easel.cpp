#include "main.hpp"

Easel::Easel()
{
    letters_.clear();
    letters_.reserve(EASEL_SIZE);
}

void Easel::fillFrom(Pocket &pocket)
{
    while (static_cast<int>(letters_.size()) < EASEL_SIZE) {
        Letter l;
        if (!pocket.draw(l)) break;
        add(l);
    }
}

void Easel::add(const Letter &l)
{
    if (static_cast<int>(letters_.size()) < EASEL_SIZE) {
        letters_.push_back(l);
    }
}

void Easel::display(std::ostream &os) const noexcept
{
    for (const auto &l : letters_) {
        os << l.character << " ";
    }
    os << std::endl;
}

int Easel::size() const noexcept
{
    return static_cast<int>(letters_.size());
}