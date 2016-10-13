#include <iostream>
#include <set>
using namespace std;

class Folder;
class Message;

class Folder {
    public:
        Folder() {}
        ~Folder() {}

        Folder(const Folder &);
        Folder & operator=(const Folder &);

        void save(Message &);
        void remove(Message &);

        void addMsg(Message *);
        void removeMsg(Message *);
    private:
        set<Message *> messages;
        void putFolderInMessages(const set<Message *> &);
        void removeFolderFromMessages();
};
class Message {
    public:
        Message() {}
        ~Message();

        Message(const string &str = ""):
            contents(str) {}

        Message(const Message &);
        Message& operator=(const Message &);
        int save(Folder &);
        int remove(Folder &);

        void addFolder(Folder *);
        void removeFolder(Folder *);
    private:
        string contents;
        set<Folder *> folders;
        void putMsgInFolders(const set<Folder *> &);
        void removeMsgFromFolders();
};

/*=================folder====================*/
void Folder::addMsg(Message *msg)
{
    messages.insert(msg);
}

void Folder::removeMsg(Message *msg)
{
    messages.erase(msg);
}

void Folder::putFolderInMessages(const set<Message *> &setMessages)
{
    for(set<Message *>::const_iterator iter = setMessages.begin();
            iter != setMessages.end(); ++iter) {
        (*iter)->addFolder(this);
    }
}

void Folder::removeFolderFromMessages()
{
    // remove this message from corresponding folders
    for(set<Message *>::iterator iter = messages.begin();
            iter != messages.end(); ++iter) {
        (*iter)->removeFolder(this);
    }
}


/*=================message====================*/
Message::Message(const Message &m):
    contents(m.contents), folders(m.folders)
{
    // add this Message to each Folder that points to m
    putMsgInFolders(folders);
}

Message & Message::operator=(const Message &rhs)
{
    if(&rhs != this) {
        removeMsgFromFolders();
        contents = rhs.contents;
        folders = rhs.folders;
        putMsgInFolders(rhs.folders);
    }

    return *this;
}

void Message::putMsgInFolders(const set<Folder *> &setFolders)
{
    for(set<Folder *>::const_iterator iter = setFolders.begin();
            iter != setFolders.end(); ++iter) {
        (*iter)->addMsg(this);
    }
}

void Message::removeMsgFromFolders()
{
    // remove this message from corresponding folders
    for(set<Folder *>::iterator iter = folders.begin();
            iter != folders.end(); ++iter) {
        (*iter)->removeMsg(this);
    }
}

Message::~Message()
{
    removeMsgFromFolders();
}

void Message::addFolder(Folder *fldr)
{
    folders.insert(fldr);
}

void Message::removeFolder(Folder *fldr)
{
    folders.erase(fldr);
}

int Message::save(Folder &fldr)
{
    addFolder(&fldr);
    fldr.addMsg(this);
}

int Message::remove(Folder &fldr)
{
    removeFolder(&fldr);
    fldr.removeMsg(this);
}

int main()
{
    return 0;
}
