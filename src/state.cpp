#include "state.hpp"

#include <algorithm>

using namespace hangman;
using namespace std;

State::State(string word) :
	m_word(word)
{}

set<char> const& State::getGuesses() const
{
	return m_guesses;
}

size_t State::getGuessCount() const
{
	return m_guesses.size();
}

string State::getGuessedWord(char unknown) const
{
	string w = m_word;
	for (size_t i = 0; i < w.size(); ++i)
		if (m_guesses.find(w[i]) == m_guesses.end())
			w[i] = unknown;
	return w;
}

State::GuessResult State::guess(char c)
{
	if (m_guesses.find(c) != m_guesses.end())
		return GuessResult::DUPLICATE;
	m_guesses.insert(c);
	if (m_word.find(c) == string::npos)
		return GuessResult::INCORRECT;
	else
		return GuessResult::CORRECT;
}
