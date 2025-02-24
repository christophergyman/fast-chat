#include <iostream>
#define ASIO_STANDALONE
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

typedef websocketpp::server<websocketpp::config::asio> server;

// Function to handle incoming messages
void on_message(server *s, websocketpp::connection_hdl hdl, server::message_ptr msg)
{
    std::cout << "Received: " << msg->get_payload() << std::endl;

    // Send the message back to the client
    try
    {
        s->send(hdl, "Server received: " + msg->get_payload(), websocketpp::frame::opcode::text);
    }
    catch (websocketpp::exception const &e)
    {
        std::cout << "Send failed: " << e.what() << std::endl;
    }
}

int main()
{
    server print_server;

    print_server.set_message_handler(std::bind(&on_message, &print_server, std::placeholders::_1, std::placeholders::_2));
    print_server.set_access_channels(websocketpp::log::alevel::all);
    print_server.set_error_channels(websocketpp::log::elevel::all);

    print_server.init_asio();
    print_server.listen(9003);
    print_server.start_accept();

    print_server.run();
}