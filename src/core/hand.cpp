#include "../inc/main.hpp"

Hand::Hand()
{
    letters_.clear();
    letters_.reserve(HAND_SIZE);
}

void Hand::fillFrom(Pocket &pocket)
{
    while (static_cast<int>(letters_.size()) < HAND_SIZE) {
        Letter l;
        if (!pocket.draw(l)) break;
        add(l);
    }
}

void Hand::add(const Letter &l)
{
    if (static_cast<int>(letters_.size()) < HAND_SIZE) {
        letters_.push_back(l);
    }
}

void Hand::display(std::ostream &os) const noexcept
{
    for (const auto &l : letters_) {
        os << l.character << " ";
    }
    os << std::endl;
}

int Hand::size() const noexcept
{
    return static_cast<int>(letters_.size());
}