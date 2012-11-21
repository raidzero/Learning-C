#include <stdio.h>
#include <dbus/dbus.h> 

int main()
{
    DBusConnection *connection;
    DBusError error;

    //init error message
    dbus_error_init(&error);
    connection = dbus_bus_get(DBUS_BUS_SESSION, &error);

    if (!connection)
    {
        printf("Connection to DBus failed: %s\n", error.message);

        //dealloc error msg
        dbus_error_free(&error);
        return 1;
    }
    
    printf("Connection to DBus succeeded!\n");

    // try to get metadata from a player interface
    DBusMessage* msg;
    DBusMessageIter args;
    DBusPendingCall* pending;

    msg = dbus_message_new_method_call("org.mrpis.audacious", "/Player", "org.freedesktop.MediaPlayer", "GetMetadata");

    if (msg == NULL)
    {
        printf("Message Null!\n");
        return 1;
    }

    // send message and get a handle for a reply
    if (!dbus_connection_send_with_reply (connection, msg, &pending, -1)) { // -1 is default timeout
        fprintf(stderr, "Out Of Memory!\n"); 
        return 1;
    }
    if (pending == NULL) { 
        fprintf(stderr, "Pending Call Null\n"); 
        return 1; 
    }
    dbus_connection_flush(connection);

    // free message
    dbus_message_unref(msg);

    int stat;
    dbus_uint32_t level;

    // block until we receive a reply
    dbus_pending_call_block(pending);

    // get the reply message
    msg = dbus_pending_call_steal_reply(pending);
    if (NULL == msg) {
        fprintf(stderr, "Reply Null\n"); 
        return 1; 
    }

    // free the pending message handle
    dbus_pending_call_unref(pending);
    
    // read the parameters
    if (!dbus_message_iter_init(msg, &args))
        printf("Message has no arguments!\n");
    else if ((DBUS_TYPE_BOOLEAN != dbus_message_iter_get_arg_type(&args)))
        printf("Argument is not boolean!\n");
    else
        dbus_message_iter_get_basic(&args, &stat);
   
   if (!dbus_message_iter_next(&args))
      fprintf(stderr, "Message has too few arguments!\n"); 
   else if (DBUS_TYPE_UINT32 != dbus_message_iter_get_arg_type(&args)) 
      fprintf(stderr, "Argument is not int!\n"); 
   else
      dbus_message_iter_get_basic(&args, &level); 
    
    printf("Got Reply: %d, %d\n", stat, level);

    return 0;
}
