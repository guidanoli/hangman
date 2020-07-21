#include "state.hpp"

#include <algorithm>

#include <gtest/gtest.h>

using namespace std;
using namespace hangman;

const string word = "jazz";

#define EXPECT_GUESSED(s, c) \
EXPECT_NE(find(s.getGuesses().begin(), s.getGuesses().end(), c), \
s.getGuesses().end())

TEST(StateTests, jazz)
{
	State s(word);
	EXPECT_TRUE(s.getGuesses().empty());
	EXPECT_EQ(s.getGuessCount(), 0);
	EXPECT_STREQ(s.getGuessedWord().c_str(), "____");
	EXPECT_STREQ(s.getGuessedWord('?').c_str(), "????");

	// j
	EXPECT_EQ(s.guess('j'), State::GuessResult::CORRECT);
	ASSERT_EQ(s.getGuesses().size(), 1);
	ASSERT_EQ(s.getGuessCount(), 1);
	EXPECT_GUESSED(s, 'j') << 'j';
	EXPECT_STREQ(s.getGuessedWord().c_str(), "j___");

	// a
	EXPECT_EQ(s.guess('a'), State::GuessResult::CORRECT);
	EXPECT_EQ(s.getGuesses().size(), 2);
	ASSERT_EQ(s.getGuessCount(), 2);
	EXPECT_GUESSED(s, 'a') << 'a';
	EXPECT_STREQ(s.getGuessedWord().c_str(), "ja__");
	
	// k
	EXPECT_EQ(s.guess('k'), State::GuessResult::INCORRECT);
	EXPECT_EQ(s.getGuesses().size(), 3);
	ASSERT_EQ(s.getGuessCount(), 3);
	EXPECT_STREQ(s.getGuessedWord().c_str(), "ja__");
	
	// z
	EXPECT_EQ(s.guess('z'), State::GuessResult::CORRECT);
	EXPECT_EQ(s.getGuesses().size(), 4);
	ASSERT_EQ(s.getGuessCount(), 4);
	EXPECT_GUESSED(s, 'z') << 'z';
	EXPECT_STREQ(s.getGuessedWord().c_str(), "jazz");
	
	// z (again)
	EXPECT_EQ(s.guess('z'), State::GuessResult::DUPLICATE);
	EXPECT_EQ(s.getGuesses().size(), 4);
	ASSERT_EQ(s.getGuessCount(), 4);
	EXPECT_GUESSED(s, 'z') << 'z' << " (again)";
	EXPECT_STREQ(s.getGuessedWord().c_str(), "jazz");
}