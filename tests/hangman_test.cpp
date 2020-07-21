#include "state.hpp"

#include <algorithm>

#include <gtest/gtest.h>

using namespace std;
using namespace hangman;

const string word = "jazz";

#define EXPECT_GUESSED(s, c) \
EXPECT_NE(find(s.getCorrectGuesses().begin(), s.getCorrectGuesses().end(), c), \
          s.getCorrectGuesses().end())

TEST(StateTests, jazz)
{
	State s(word);
	EXPECT_TRUE(s.getCorrectGuesses().empty());
	EXPECT_TRUE(s.getIncorrectGuesses().empty());
	EXPECT_STREQ(s.getGuessedWord().c_str(), "____");
	EXPECT_STREQ(s.getGuessedWord('?').c_str(), "????");
	EXPECT_FALSE(s.guessedWord());

	// j
	EXPECT_EQ(s.guess('j'), GuessResult::CORRECT);
	ASSERT_EQ(s.getCorrectGuesses().size(), 1);
	ASSERT_EQ(s.getIncorrectGuesses().size(), 0);
	EXPECT_GUESSED(s, 'j') << 'j';
	EXPECT_STREQ(s.getGuessedWord().c_str(), "j___");
	EXPECT_FALSE(s.guessedWord());

	// a
	EXPECT_EQ(s.guess('a'), GuessResult::CORRECT);
	ASSERT_EQ(s.getCorrectGuesses().size(), 2);
	ASSERT_EQ(s.getIncorrectGuesses().size(), 0);
	EXPECT_GUESSED(s, 'a') << 'a';
	EXPECT_STREQ(s.getGuessedWord().c_str(), "ja__");
	EXPECT_FALSE(s.guessedWord());

	// k
	EXPECT_EQ(s.guess('k'), GuessResult::INCORRECT);
	ASSERT_EQ(s.getCorrectGuesses().size(), 2);
	ASSERT_EQ(s.getIncorrectGuesses().size(), 1);
	EXPECT_STREQ(s.getGuessedWord().c_str(), "ja__");
	EXPECT_FALSE(s.guessedWord());
	
	// z
	EXPECT_EQ(s.guess('z'), GuessResult::CORRECT);
	ASSERT_EQ(s.getCorrectGuesses().size(), 3);
	ASSERT_EQ(s.getIncorrectGuesses().size(), 1);
	EXPECT_GUESSED(s, 'z') << 'z';
	EXPECT_STREQ(s.getGuessedWord().c_str(), "jazz");
	EXPECT_TRUE(s.guessedWord());
	
	// z (again)
	EXPECT_EQ(s.guess('z'), GuessResult::DUPLICATE);
	ASSERT_EQ(s.getCorrectGuesses().size(), 3);
	ASSERT_EQ(s.getIncorrectGuesses().size(), 1);
	EXPECT_GUESSED(s, 'z') << 'z' << " (again)";
	EXPECT_STREQ(s.getGuessedWord().c_str(), "jazz");
	EXPECT_TRUE(s.guessedWord());
}