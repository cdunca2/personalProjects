#include "polygonal.h"

vertex::vertex(double _x, double _y) {
    x = _x;
    y = _y;
    ishead = false;
}

polygon::polygon() {

}

polygon::polygon(int sides) {
    double newx, newy;

    for(int i=0; i<sides; i++)
    {
        newx = cos(2.0 * M_PIl * i / sides);
        newy = sin(2.0 * M_PIl * i / sides);

        add_vert(newx, newy);
    }
}

polygon::polygon(SHAPE myshape) {
    double newx, newy;

    switch(myshape) {
        case star:
            for(int i=0; i<5; i++)
            {
                newx = cos(2.0 * M_PIl * i / 5);
                newy = sin(2.0 * M_PIl * i / 5);

                add_vert(newx, newy);

                newx += cos(2.0 * M_PIl * (i+1) / 5);
                newx /= 4;
                newy += sin(2.0 * M_PIl * (i+1) / 5);
                newy /= 4;

                add_vert(newx, newy);
            }
        break;
        case rhombus:
            for(int i=0; i<4; i++)
            {
                newx = cos(2.0 * M_PIl * i / 7);
                newy = sin(2.0 * M_PIl * i / 5);

                if(i%2)
                    newx /= 2;
                else
                    newy /= 2;

                add_vert(newx, newy);
            }
        break;
    }
}

void polygon::add_vert(double x, double y)
{
    vertex* newvert = new vertex(x, y);

    if(!vertexes) {
        newvert->ishead = true;
        newvert->next = newvert;
        newvert->prev = newvert;
        vertexes = newvert;
    }
    else {
        vertex* temp = vertexes;
        newvert->next = temp;
        newvert->prev = temp->prev;
        temp->prev->next = newvert;
        temp->prev = newvert;
    }
}

void polygon::do_split()
{
    vertex* temp = vertexes;
    vertex* mid = NULL;

    double mid_x, mid_y;
    do {
        mid_x = (temp->x + temp->next->x) / 2;
        mid_y = (temp->y + temp->next->y) / 2;

        mid = new vertex(mid_x, mid_y);

        mid->prev = temp;
        mid->next = temp->next;
        temp->next->prev = mid;
        temp->next = mid;

        temp = temp->next->next;
    } while(!temp->ishead);

    vertexes = temp;
}

void polygon::do_average(int numweights, vector<int> weights)
{
    vertex* temp = vertexes;
    vertex* templeft = temp->prev;
    vertex* tempright = temp->next;
    vector<pair<double,double>> wgtd = vector<pair<double,double>>();
    double newx = 0, newy = 0, tweight;
    int rshift = 0;

    for(int i=0; i<numweights; i++)
        tweight += weights[i];

    do {
        newx = 0;
        newy = 0;

        if(numweights % 2) {
            newx += temp->x * (double)weights[numweights/2];
            newy += temp->y * (double)weights[numweights/2];
            rshift = 0;
        }
        else {
            templeft = templeft->next;
            rshift = -1;
        }

        for(int i=1; i<=numweights/2; i++) {
            newx += templeft->x * weights[numweights/2 - i];
            newy += templeft->y * weights[numweights/2 - i];
            newx += tempright->x * weights[numweights/2 + i + rshift];
            newy += tempright->y * weights[numweights/2 + i + rshift];
            templeft = templeft->prev;
            tempright = tempright->next;
        }
        wgtd.push_back(make_pair(newx / tweight, newy / tweight));
        temp = temp->next;
        templeft = temp->prev;
        tempright = temp->next;
    } while(!temp->ishead);

    for(vector<pair<double,double>>::iterator it = wgtd.begin(); it != wgtd.end(); it++) {
        pair<double,double> temppair = *it;
        temp->x = temppair.first;
        temp->y = temppair.second;
        temp = temp->next;
    }

    vertexes = temp;
}

void polygon::print_verts()
{
    vertex* temp = vertexes;

    do {
        cout << "head? " << temp->ishead << "  X: " << temp->x << "  Y: " << temp->y << endl;
        temp = temp->next;
    } while(!temp->ishead);
}

/*int main(int argc, char* argv[])
{
    int numsides = atoi(argv[1]);
    int weights[argc - 2];
    int numweights = 0;
    for(int i=0; i<argc-2; i++) {
        weights[i] = atoi(argv[i+2]);
        numweights++;
    }

    polygon datshape(numsides);

    datshape.print_verts();
    cout << endl;

    datshape.do_split();

    datshape.print_verts();
    cout << endl;

    datshape.do_average(numweights, weights);

    datshape.print_verts();
    cout << endl;
}*/
