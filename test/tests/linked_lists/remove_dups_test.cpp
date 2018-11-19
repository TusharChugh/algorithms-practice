#include <linked_lists/remove_dups.h>
#include <gtest/gtest.h>

using algorithm::Forward_List;
using algorithm::remove_duplicates_map;

template<class T> void print_list( Forward_List<T>& input ) {
    auto head = input.front();
    while ( head ) {
        std::cout << head->value_ << " ";
        head = head->next_;
    }
    std::cout << std::endl;
}

TEST( REMOVE_DUPS, EMPTY_LIST ) {
    Forward_List<int> list;

    remove_duplicates_map( list );

    ASSERT_EQ( 0, list.size() );
}

TEST( REMOVE_DUPS, ONE_ELEMENT ) {
    int input = 1;
    Forward_List<int> list;
    list.push_front( input );

    remove_duplicates_map( list );

    ASSERT_EQ( input, list.front()->value_ );
}

TEST( REMOVE_DUPS, ONE_DUPLICATE ) {
    std::array<int, 5> input{1, 2, 2, 3, 4};
    Forward_List<int> list;
    for ( auto& num : input ) {
        list.push_front( num );
    }

    remove_duplicates_map( list );

    std::vector<int> output = {4, 3, 2, 1};
    auto head               = list.front();
    for ( size_t i = 0; i < output.size(); ++i ) {
        ASSERT_EQ( output[i], head->value_ );
        head = head->next_;
    }
}

TEST( REMOVE_DUPS, END_DUPLICATE ) {
    std::array<int, 5> input{1, 1, 2, 3, 4};
    Forward_List<int> list;
    for ( auto& num : input ) {
        list.push_front( num );
    }

    remove_duplicates_map( list );

    std::vector<int> output = {4, 3, 2, 1};
    auto head               = list.front();
    for ( size_t i = 0; i < output.size(); ++i ) {
        ASSERT_EQ( output[i], head->value_ );
        head = head->next_;
    }
}