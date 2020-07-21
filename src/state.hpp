#ifndef HANGMAN_STATE_H
#define HANGMAN_STATE_H

#include <string>
#include <set>

namespace hangman
{

	class State
	{
	public:
		enum class GuessResult
		{
			CORRECT,
			INCORRECT,
			DUPLICATE,
		};
	private:
		std::string m_word;
		std::set<char> m_guesses;
	public:
		State(std::string word);
		std::set<char> const& getGuesses() const;
		std::size_t getGuessCount() const;
		std::string getGuessedWord(char unknown = '_') const;
		GuessResult guess(char c);
	};

}

#endif