#include "CipherFactory.hpp"

#include "CaesarCipher.hpp"
#include "VigenereCipher.hpp"
#include "PlayfairCipher.hpp"

#include <memory>
#include <stdexcept>

std::unique_ptr<Cipher> CipherFactory::makeCipher(
    const CipherType type,
    const std::string& key
)
{
    switch (type)
    {
        case CipherType::Caesar:
            return std::make_unique<CaesarCipher>(std::stoi(key));

        case CipherType::Vigenere:
            return std::make_unique<VigenereCipher>(key);

        case CipherType::Playfair:
            return std::make_unique<PlayfairCipher>(key);
    }

    throw std::invalid_argument("Unknown CipherType");
}
