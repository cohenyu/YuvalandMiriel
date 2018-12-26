#include "ConnectCommand.h"
#include "Expression.h"
#include "ShuntingYard.h"
#include "TCPClient.h"

/*
 * this is the constructor of the ConnectCommand.
 */
ConnectCommand::ConnectCommand(SymbolTableManager* stm) {
    this->stm = stm;
}
/*
 * this function execute the connect command
 * the connect command have 2 parameters so we take then and calculate
 * 2 expression.
 * the connect have port and ip
 */
int ConnectCommand::doCommand(vector<string> data, int index) {

    ShuntingYard shuntingYard(stm);
    Expression *exp;
    int port;
    string ipAddress;

    ipAddress = data[index + 1];

    exp = shuntingYard.fromInfixToExp(data[index + 2]);
    port = static_cast<int>(exp->calculate());
    delete exp;

    TCPClient *client = new TCPClient(ipAddress,port);
    client->connectToServer();

    this->stm->setClient(client);
    return 3;
}
