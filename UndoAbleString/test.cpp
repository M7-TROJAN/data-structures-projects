#include <iostream>
#include "UndoAbleString.h"

using namespace std;

int main()
{

    cout << "\n\n\t\t\t\t\t\t Undo/Redo Project\n\n";

    UndoAbleString S1;

    cout << "\nS1  = " << S1.Value << "\n";

    S1.Value = "Mahmoud";

    cout << "S1  = " << S1.Value << "\n";

    S1.Value = "Mahmoud2";

    cout << "S1  = " << S1.Value << "\n";

    S1.Value = "Mahmoud3";

    cout << "S1  = " << S1.Value << "\n";

    cout << "\n\nUndo: ";
    cout << "\n__________\n";

    S1.Undo();
    cout << "\nS1  after undo = " << S1.Value << "\n";

    S1.Undo();
    cout << "S1  after undo = " << S1.Value << "\n";

    S1.Undo();
    cout << "S1  after undo = " << S1.Value << "\n";

    cout << "\n\nRedo: ";
    cout << "\n__________\n";

    S1.Redo();
    cout << "\nS1  after Redo = " << S1.Value << "\n";

    S1.Redo();
    cout << "S1  after Redo = " << S1.Value << "\n";

    S1.Redo();
    cout << "S1  after Redo = " << S1.Value << "\n";

    return 0;
}
