#include "profileDB.hpp"

void ProfileDB::add_profile(std::string name, Profile new_profile) {
    profile_table.insert({name, new_profile});
}
Profile ProfileDB::get_profile(std::string name) {
    return profile_table[name];
}


ProxyProfileDB::ProxyProfileDB(std::shared_ptr<ProfileDB> profile_db) 
    : profile_db{profile_db} {}


void ProxyProfileDB::update() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cached_profile_table = profile_db->profile_table;
    already_cached=1;
}   

void ProxyProfileDB::add_profile(std::string name, Profile new_profile) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    profile_db->add_profile(name, new_profile);
    if (already_cached)
        cached_profile_table.insert({name, new_profile});
}

Profile ProxyProfileDB::get_profile(std::string name) {
    if (!already_cached)
        this->update();
    return cached_profile_table[name];
}