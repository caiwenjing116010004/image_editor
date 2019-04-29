#include "light_adjustments.h"


imgSDHL::imgSDHL() {
    Shadow = 0;
    Highlight = 255;
    initializeTable();
}


imgSDHL::~imgSDHL() {

}


void imgSDHL::initializeTable() {
    for (int i = 0; i < 256; i++) {
        colorTables[i] = (uchar) i;
    }
}


void imgSDHL::setShadow(int p_shadow = 0) {
    if (p_shadow < 0 || p_shadow > 255) {
        cout << "Specified shadow degree out of valid range." << endl;
        return;
    }
    else {
        Shadow = p_shadow;
    }
}


void imgSDHL::setHighlight(int p_highlight = 0) {
    if (p_highlight < 0 || p_highlight > 255) {
        cout << "Specified highlight degree out of valid range." << endl;
        return;
    }
    else {
        Highlight = 255 - p_highlight;
    }
}


bool imgSDHL::createTable()
{
    if (Highlight > 255 || (Highlight - Shadow) > 255 || (Highlight - Shadow) < 2) {
        cout << "Fail to create table" << endl;
        return false;
    }

    int diff = (int)(Highlight - Shadow);
    double coef = 255.0 / diff;

    for (int i = 0; i < 256; i ++)
    {
        int newValue;
        if ( colorTables[i] <= (uchar)Shadow ) {
            newValue = 0;
        }
        else {
            newValue = (int)((colorTables[i] - Shadow) * coef + 0.5);
            if (newValue > 255) newValue = 255;
        }

        newValue = (int)(newValue / 255.0 * 255.0 + 0.5 );
        colorTables[i] = (uchar)(newValue);
    }

    return true;
}


int imgSDHL::adjust(Mat input, Mat output)
{
    int width = input.cols;
    int height = input.rows;

    bool flag = createTable();
    if (!flag) {
        cout << "Fail to create table" << endl;
        return 1;
    }

    for (int row_i = 0; row_i < height; row_i ++)
    {
        for (int col_i = 0; col_i < width; col_i ++)
        {
            for (int c = 0; c < 3; c++)
            {
                uchar old = input.at<Vec3b>(row_i, col_i)[c];
                uchar New = colorTables[old];
                output.at<Vec3b>(row_i, col_i)[c] = New;
            }
        }
    }

    return 0;
}
