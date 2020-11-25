#include <libssh/libssh.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int main()
{
    ssh_session my_ssh_session;
    int rc;
    char *password;
    my_ssh_session = ssh_new();
    if (my_ssh_session == NULL)
        exit(-1);
    ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, "192.168.0.108");
    ssh_options_set(my_ssh_session, SSH_OPTIONS_PORT, 443);
    ssh_options_set(my_ssh_session, SSH_OPTIONS_USER, "teste");
    if (verify_knowhost(my_ssh_session) < 0){
        ssh_disconnect(my_ssh_session);
        ssh_free(my_ssh_session);
        printf('[-] Ocorreu um erro ao iniciar sessao SSH\n');
        exit(-1);
    }
    password = ("123");
    rc = ssh_userauth_password(my_ssh_session, NULL, password);
    ssh_disconnect(my_ssh_session);
    ssh_disconnect(my_ssh_session);
    printf('[-] Ocorreu um erro ao iniciar sessao SSH\n');
    ssh_free(my_ssh_session);
}