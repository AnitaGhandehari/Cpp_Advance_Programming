#include "follower_info.h"


void follower_info::set_user_id(int in_user_id)
{
    user_id = in_user_id;
}
void follower_info::set_followings(std::vector<int> in_followings)
{
    followings = in_followings;
}
void follower_info::set_followers(std::vector<int> in_followers)
{
    followers = in_followers;
}