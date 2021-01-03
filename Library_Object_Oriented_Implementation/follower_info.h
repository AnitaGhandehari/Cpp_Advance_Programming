
#ifndef A4_FOLLOWER_INFO_H
#define A4_FOLLOWER_INFO_H

#include <vector>

class follower_info
{
private:
    int user_id;
    std::vector<int> followings;
    std::vector<int> followers;
public:
    void set_user_id(int in_user_id);
    void set_followings(std::vector<int> in_followings);
    void set_followers(std::vector<int> in_followers);

    int get_user_id(){ return user_id; };
    std::vector<int> get_followings(){ return followings; };
    std::vector<int> get_followers(){ return followers; };
};

#endif //A4_FOLLOWER_INFO_H
