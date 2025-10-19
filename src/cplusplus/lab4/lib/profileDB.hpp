#pragma once

#include "profile.hpp"
#include <map>
#include <string>
#include <memory>
// to imitate awaiting response time
#include <chrono>
#include <thread>


class IProfileDB {
protected:
    // virtual std::map<std::string, Profile> get_table();
public:
    virtual void add_profile(std::string name, Profile new_profile)=0;
    virtual Profile get_profile(const std::string name)=0;

    virtual ~IProfileDB() {};
};

class ProfileDB : public IProfileDB {
protected:
    std::map<std::string, Profile> profile_table = {};
    // virtual std::map<std::string, Profile> get_table() override;

public:
    void add_profile(std::string name, Profile new_profile) override;
    Profile get_profile(const std::string name) override;

    friend class ProxyProfileDB;
};

class ProxyProfileDB : public IProfileDB {
protected:
    std::shared_ptr<ProfileDB> profile_db;
    std::map<std::string, Profile> cached_profile_table;
    int already_cached=0;

public:
    ProxyProfileDB(std::shared_ptr<ProfileDB> profile_db);

    void update();
    void add_profile(std::string name, Profile new_profile) override;
    Profile get_profile(const std::string name) override;
};