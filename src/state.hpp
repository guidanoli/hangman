#ifndef HANGMAN_STATE_H
#define HANGMAN_STATE_H

#include <string>
#include <set>

namespace hangman
{

	enum class GuessResult
	{
		CORRECT,
		INCORRECT,
		DUPLICATE
	};

	class State
	{
	private:
		std::string m_word;
		std::set<char> m_correct_guesses;
		std::set<char> m_incorrect_guesses;
	public:
		State(std::string word);
		std::set<char> const& getCorrectGuesses() const;
		std::set<char> const& getIncorrectGuesses() const;
		std::string getGuessedWord(char unknown = '_') const;
		bool guessedWord() const;
		GuessResult guess(char c);
	};

}

#endif