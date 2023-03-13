struct BaseState
{
    enum class EStates : uint8_t { Q1, Q2, Q3 };
    virtual EStates transition(const char command) = 0;
};

struct Q1 : BaseState
{
    virtual EStates transition(const char command) override
    {
        return command == '1' ? BaseState::EStates::Q2 : BaseState::EStates::Q1;
    }
};

struct Q2 : BaseState
{
    virtual EStates transition(const char command) override
    {
        return command == '0' ? BaseState::EStates::Q3 : BaseState::EStates::Q2;
    }
};

struct Q3 : BaseState
{
    virtual EStates transition(const char command) override
    {
        (void)command;
        return BaseState::EStates::Q2;
    }
};

class Automaton
{
private:
    Q1* _q1; Q2* _q2; Q3* _q3;
    BaseState::EStates _current_state;
    std::map<BaseState::EStates, BaseState*> _states;

public:
    Automaton()
    {
        _q1 = new Q1();
        _q2 = new Q2();
        _q3 = new Q3();
        _current_state = BaseState::EStates::Q1;
        _states = {{ BaseState::EStates::Q1, _q1},
                   { BaseState::EStates::Q2, _q2},
                   { BaseState::EStates::Q3, _q3}};
    }

    bool read_commands(const std::vector<char>& commands)
    {
        for (auto c : commands) _current_state = _states[_current_state]->transition(c);
        return (_current_state == BaseState::EStates::Q2) ? true : false;
    }
};