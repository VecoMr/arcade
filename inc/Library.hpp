/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-alexandre.douard
** File description:
** Library
*/

#pragma once
namespace arcade {
    template <typename T>
    class Library {
        public:
            Library() = default;
            Library(const Library<T>& other) noexcept;
            Library(std::shared_ptr<void> lib, const std::string &path);
            ~Library() = default;

            std::unique_ptr<T>& getInst() noexcept { return _inst; }

            T* operator->() const noexcept;
            T& operator*() const noexcept;

            Library& operator=(Library<T>&& other) noexcept;

        private:
            std::shared_ptr<void> _lib;
            std::unique_ptr<T> _inst;
    };

    template <typename T>
    Library<T>::Library(const Library<T>& other) noexcept
        : _lib(std::move(other._lib)), _inst(std::move(other._inst)) {}

    template <typename T>
    Library<T>::Library(std::shared_ptr<void> lib, const std::string &path)
        : _lib(lib), _inst(reinterpret_cast<T *(*)()>(dlsym(lib.get(), path.c_str()))()) {}

    template <typename T>
    T* Library<T>::operator->() const noexcept {
        return this->_inst.get();
    }

    template <typename T>
    T& Library<T>::operator*() const noexcept {
        return *(this->_inst);
    }

    template<typename T>
    Library<T>& Library<T>::operator=(Library<T>&& other) noexcept {
        if (this != &other) {
            _inst = std::move(other._inst);
            _lib = std::move(other._lib);
        }
        return *this;
    }
}