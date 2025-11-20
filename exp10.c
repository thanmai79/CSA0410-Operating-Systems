#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct message {
    long msg_type;
    char msg_text[100];
};

// Simulated message queue structure
struct simulated_queue {
    struct message msg;
    int has_message;
};

struct simulated_queue msg_queue = {0};

void simulated_msgsnd(struct message *msg) {
    memcpy(&msg_queue.msg, msg, sizeof(struct message));
    msg_queue.has_message = 1;
    printf("Producer: Data sent to simulated queue: %s\n", msg->msg_text);
}

int simulated_msgrcv(struct message *msg) {
    if (msg_queue.has_message) {
        memcpy(msg, &msg_queue.msg, sizeof(struct message));
        msg_queue.has_message = 0;
        printf("Consumer: Data received from simulated queue: %s\n", msg->msg_text);
        return 1;
    }
    return 0;
}

int main() {
    struct message msg;
    msg.msg_type = 1;
    
    // Producer: Send a message
    strcpy(msg.msg_text, "Hello, simulated message queue!");
    simulated_msgsnd(&msg);
    
    // Consumer: Receive the message
    simulated_msgrcv(&msg);
    
    printf("Message queue simulation completed successfully!\n");
    return 0;
}