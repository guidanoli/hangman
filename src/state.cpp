#include "state.hpp"

#include <algorithm>

using namespace hangman;
using namespace std;

State::State(string word) :
	m_word(word)
{}

set<char> const& State::getCorrectGuesses() const
{
	return m_correct_guesses;
}

set<char> const& State::getIncorrectGuesses() const
{
	return m_incorrect_guesses;
}

string State::getGuessedWord(char unknown) const
{
	string w = m_word;
	for (size_t i = 0; i < w.size(); ++i)
		if (m_correct_guesses.find(w[i]) == m_correct_guesses.end())
			w[i] = unknown;
	return w;
}

bool hangman::State::guessedWord() const
{
	for (size_t i = 0; i < m_word.size(); ++i)
		if (m_correct_guesses.find(m_word[i]) == m_correct_guesses.end())
			return false;
	return true;
}

GuessResult State::guess(char c)
{
	if (m_correct_guesses.find(c) != m_correct_guesses.end() ||
		m_incorrect_guesses.find(c) != m_incorrect_guesses.end())
		return GuessResult::DUPLICATE;

	if (m_word.find(c) == string::npos) {
		m_incorrect_guesses.insert(c);
		return GuessResult::INCORRECT;
	} else {
		m_correct_guesses.insert(c);
		return GuessResult::CORRECT;
	}
}
