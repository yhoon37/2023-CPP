#include <filesystem>
#include <iostream>
#include <string>

using namespace std;
namespace fs = std::filesystem;

int main() {

    fs::path p1 ("C:/Users/user/CLionProjects/untitled");          cout << p1 << endl;

    fs::path p2 ("C:\\Windows") ;    p2 += "/Fonts" ;    cout << p2 << endl;

    fs::path p3 ("./main.cpp");          cout << p3 << endl;

    for(const auto& sub_path : p1)
        cout << sub_path << endl;

    fs::directory_entry dir (p3);
    if ( dir.exists() and dir.is_regular_file() )
        cout << " file size: " << dir.file_size() << endl;


    //현재 디렉토리의 파일명을 출력함
    for (const auto& file : fs::directory_iterator("./")) {
        if (is_regular_file(file)) {
            cout << file.path() << endl;
        }
    }


    //현재 디렉토리의 파일명 및 서브 디렉토리의 파일명을 모두 출력함
    fs::directory_entry p ("./");
    auto begin = fs::recursive_directory_iterator(p);
    auto end = fs::recursive_directory_iterator();
    for(auto it = begin; it != end; ++it){
        const string blank(it.depth()*2, ' ');
        auto& entry = *it;
        if(fs::is_regular_file(entry)){
            cout << blank << " F " << entry;
            cout << " (" << file_size(entry) << ") bytes " << endl;
        } else if (fs::is_directory(entry)){
            cout << blank << " D " << entry << endl;
        }
    }
}