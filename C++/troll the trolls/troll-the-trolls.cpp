namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.

enum class AccountStatus {
    troll,
    guest,
    user,
    mod
};

enum class Action {
    read,
    write,
    remove
};

// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.

bool display_post(AccountStatus poster,AccountStatus viewer) {
    if (poster == AccountStatus::troll) {
        return viewer == AccountStatus::troll;
    } else {
        return true;
    }
}

// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.

bool permission_check(Action action, AccountStatus accountType) {
    switch (accountType) {
        case AccountStatus::mod:
            return true;
            break;
        case AccountStatus::user:
        case AccountStatus::troll:
            return action != Action::remove;
            break;
        case AccountStatus::guest:
            return action == Action::read;
            break;
        default:
            return false;
    }
}

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.

bool valid_player_combination (AccountStatus player1, AccountStatus player2) {
    switch(player1) {
        case AccountStatus::guest:
            return false;
        case AccountStatus::troll:
            return player2 == AccountStatus::troll;
        case AccountStatus::user:
        case AccountStatus::mod:
            return player2 != AccountStatus::guest && player2 != AccountStatus::troll;
        default:
            return false;
    }
}

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.

bool has_priority (AccountStatus player1, AccountStatus player2) {
    switch(player1) {
        case AccountStatus::mod:
            return player2 != AccountStatus::mod;
        case AccountStatus::user:
            return player2 == AccountStatus::guest || player2 == AccountStatus::troll;
        case AccountStatus::guest:
            return player2 == AccountStatus::troll;
        case AccountStatus::troll:
            return false;
        default:
            return false;
    }
}


}  // namespace hellmath