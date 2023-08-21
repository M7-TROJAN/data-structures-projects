// Copyright (c) [2021] [Mahmoud Mohamed]
// Licensed under the MIT License.

#pragma once

#include <iostream>
#include <stack>

class UndoAbleString
{

private:
    std::stack<std::string> _Undo;
    std::stack<std::string> _Redo;
    std::string _Value;

public:
    void Set(std::string value)
    {
        _Undo.push(_Value);
        _Value = value;
    }

    std::string Get()
    {
        return _Value;
    }

    __declspec(property(get = Get, put = Set)) std::string Value;

    void Undo()
    {

        if (!_Undo.empty())
        {
            _Redo.push(_Value);
            _Value = _Undo.top();
            _Undo.pop();
        }
    }

    void Redo()
    {

        if (!_Redo.empty())
        {
            _Undo.push(_Value);
            _Value = _Redo.top();
            _Redo.pop();
        }
    }
};
