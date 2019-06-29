#include <igl/readPLY.h>
#include <igl/opengl/glfw/Viewer.h>
#include <igl/opengl/glfw/imgui/ImGuiMenu.h>
#include <igl/opengl/glfw/imgui/ImGuiHelpers.h>
#include <igl/vertex_triangle_adjacency.h>
#include <igl/writePLY.h>
#include <igl/file_exists.h>
#include <imgui/imgui.h>
#include <iostream>
#include <random>
#include "mytools.h"
#include <Eigen/SVD>



#include <unistd.h>


class MyContext
{
public:

	std::string sourceFile1 = "../../data/bunny.obj";
	//std::string sourceFile1 = "../../data/camel.obj";
	//std::string sourceFile1 = "../../data/cow.obj";
	//std::string sourceFile1 = "../../data/cube.obj";
	//std::string sourceFile1 = "../../data/dragon.obj";


	MyContext() :GaussianNoise(0.0), point_size(8), line_width(0.5), k(1), mode(0)//, model(0)
	{
	
		//initial vertices and faces
		if (!igl::file_exists(sourceFile1) )//|| !igl::file_exists(sourceFile2))

		{
            char *path=NULL;
            size_t size;
            path=getcwd(path,size);
            std::cout<<"\n current Path"<<path;
			std::cout << "[error] cannot locate model file at '../data/XXX.obj' \nPress any key to exit\n";
			char c;
			std::cin >> c;
			exit(1);
		}
        std::cout<<"eigen version.:"<<EIGEN_WORLD_VERSION<<"."<<EIGEN_MAJOR_VERSION <<"."<< EIGEN_MINOR_VERSION<<"\n";

        //CLION
        //igl::readOBJ(sourceFile1, m1_V, m1_F);


	}
	~MyContext() {}


	Eigen::MatrixXd m1_V;
	Eigen::MatrixXi m1_F;
	Eigen::VectorXd H; // mean curvature
	Eigen::VectorXd GC; // gaussian curvature
    int model = 0;
    float lambda = 1e-7;
	float GaussianNoise;
	float point_size;
	float line_width;
    int k;
	int mode;
	int maxIter = 100;

	void reset_display(igl::opengl::glfw::Viewer& viewer)
	{
		static std::default_random_engine generator;
		viewer.data().clear();
        viewer.data().show_lines = 0;
        viewer.data().show_overlay_depth = 1;

		if (mode == 1)
		{
			std::cout << " uniform LPB : MEAN " << std::endl;

			H = getH(m1_V,m1_F,false);
			H = 100 * H.array() / (H.maxCoeff() - H.minCoeff());
			viewer.data().set_mesh(m1_V, m1_F);
			viewer.data().set_colors(H);
			viewer.core.align_camera_center(m1_V, m1_F);
		}
		else if(mode == 2){
			std::cout << " cotan LPB : MEAN " << std::endl;

			H = getH(m1_V,m1_F,true);
			H = 100 * H.array() / (H.maxCoeff() - H.minCoeff());
			viewer.data().set_mesh(m1_V, m1_F);
			viewer.data().set_colors(H);
			viewer.core.align_camera_center(m1_V, m1_F);
		}
		else if(mode == 3){
			std::cout << " cotan LPB : MEAN with igl functions (for comparison)" << std::endl;

			H.resize(m1_V.rows());

			Eigen::SparseMatrix<double> L, Area, AreaInv;
			igl::cotmatrix(m1_V,m1_F, L);
			igl::massmatrix(m1_V, m1_F, igl::MASSMATRIX_TYPE_BARYCENTRIC, Area );
			//igl::invert_diag(Area,AreaInv);
			AreaInv = invertDiagSparseMatrix(Area);

			H = 0.5*(AreaInv*(L*m1_V)).rowwise().norm();
			H = 100 * H.array() / (H.maxCoeff() - H.minCoeff());

            viewer.data().set_mesh(m1_V, m1_F);
            viewer.data().set_colors(H);
            viewer.core.align_camera_center(m1_V, m1_F);
		}
        else if(mode == 4){

			std::cout << " Gauss Curvature " << std::endl;
			GC = getGaussCurv(m1_V, m1_F);
			GC = 100 * GC.array() / (GC.maxCoeff() - GC.minCoeff());
            viewer.data().set_mesh(m1_V, m1_F);
            viewer.data().set_colors(GC);
            viewer.core.align_camera_center(m1_V, m1_F);
            
        }
        else if(mode == 5){
			std::cout << " Spectral meshes " << std::endl;
			Eigen::MatrixXd new_V;
			new_V = getSpectralMeshes(m1_V,m1_F,k);
			viewer.data().set_mesh(new_V, m1_F);
			viewer.core.align_camera_center(new_V, m1_F);
            //std::string filename = "my_bun.ply";
            //igl::writePLY(filename, V, F);
        }
		else if(mode == 6){
			std::cout << " explicit LPB smoothing " << std::endl;
			//Eigen::MatrixXd new_V;
			m1_V = explicit_LPB_smoothing(m1_V,m1_F,lambda,maxIter);


			viewer.data().set_mesh(m1_V, m1_F);
			viewer.core.align_camera_center(m1_V, m1_F);
		}
		else if(mode == 7){
			std::cout << " implicit LPB smoothing " << std::endl;
			Eigen::MatrixXd new_V;
			m1_V = implicit_LPB_smoothing(m1_V,m1_F,lambda,maxIter);

			viewer.data().set_mesh(m1_V, m1_F);
			viewer.core.align_camera_center(m1_V, m1_F);
		}
		else if(mode == 8){
			std::cout << " adding gaussian noise " << std::endl;
			addGaussNoise(m1_V,GaussianNoise);

			viewer.data().set_mesh(m1_V, m1_F);
			viewer.core.align_camera_center(m1_V, m1_F);
		}
		else
        {
			std::cout << "Resetting " << std::endl;

            switch(model){
                default:
                    sourceFile1 = "../../data/bunny.obj";
                    break;
                case 1:
                    sourceFile1 = "../../data/camel.obj";
                    break;
                case 2:
                    sourceFile1 = "../../data/cow.obj";
                    break;
                case 3:
                    sourceFile1 = "../../data/cube.obj";
                    break;
                case 4:
                    sourceFile1 = "../../data/dragon.obj";
                    break;
				case 5:
					sourceFile1 = "../../data/cow_manifold.obj";
					break;
            }

			igl::readOBJ(sourceFile1, m1_V, m1_F);
            viewer.data().set_mesh(m1_V, m1_F);
			viewer.core.align_camera_center(m1_V, m1_F);
			viewer.data().show_overlay_depth = 1;
			viewer.data().show_overlay = 1;
		}

        //get_axis(my_axis);
        //viewer.data().add_points(my_axis, Eigen::RowVector3d(1, 1, 1));

		//======================================================================
		//viewer.data().add_points(m1_V,Eigen::RowVector3d(0, 0, 0));
		//viewer.data().set_mesh(m1_V,m1_F);
        
		//viewer.data().add_points(m2_V,Eigen::RowVector3d(0.5,0.5,0.5));

		//viewer.core.align_camera_center(m1_V, m1_F);

		//viewer.data().set_face_based(true);

		viewer.data().line_width = line_width;
		viewer.data().point_size = point_size;

	}

private:

};

MyContext g_myctx;


bool key_down(igl::opengl::glfw::Viewer& viewer, unsigned char key, int modifier)
{

	std::cout << "Key: " << key << " " << (unsigned int)key << std::endl;
	if (key=='q' || key=='Q')
	{
		exit(0);
	}
	return false;
}


int main(int argc, char *argv[])
{

    std::cout<<"eigen version.:"<<EIGEN_WORLD_VERSION<<","<<EIGEN_MAJOR_VERSION << EIGEN_MINOR_VERSION<<"\n";
    // load data
    Eigen::MatrixXd m1_V;
    Eigen::MatrixXd m1_VN;
    Eigen::MatrixXi m1_F;
    
    //get_example_mesh("camelhead.off", V, F, VN);
    /*
    get_example_mesh("bunny.obj", m1_V, m1_F, m1_VN);
    
    Eigen::VectorXd H;
    H = getH(m1_V, m1_F,false);
    H = 100 * H.array() / (H.maxCoeff() - H.minCoeff());
	std::cout << "H \n" << H << std::endl;
    igl::parula(H, false, g_myctx.m_H);
    
    Eigen::VectorXd GC;
    GC = getGaussCurv(m1_V, m1_F);
	//GC = 100 * GC.array() / (GC.maxCoeff() - GC.minCoeff());
    igl::parula(GC, false, g_myctx.m_GC);
    */
    //################################################################
	//################################################################
	// Init the viewer
	igl::opengl::glfw::Viewer viewer;

	// Attach a menu plugin
	igl::opengl::glfw::imgui::ImGuiMenu menu;
	viewer.plugins.push_back(&menu);

	// menu variable Shared between two menus
	double doubleVariable = 0.1f; 

	// Add content to the default menu window via defining a Lambda expression with captures by reference([&])
	menu.callback_draw_viewer_menu = [&]()
	{
		// Draw parent menu content
		menu.draw_viewer_menu();

		// Add new group
		if (ImGui::CollapsingHeader("New Group", ImGuiTreeNodeFlags_DefaultOpen))
		{
			// Expose variable directly ...
			ImGui::InputDouble("double", &doubleVariable, 0, 0, "%.4f");

			// ... or using a custom callback
			static bool boolVariable = true;
			if (ImGui::Checkbox("bool", &boolVariable))
			{
				// do something
				std::cout << "boolVariable: " << std::boolalpha << boolVariable << std::endl;
			}

			// Expose an enumeration type
			enum Orientation { Up = 0, Down, Left, Right };
			static Orientation dir = Up;
			ImGui::Combo("Direction", (int *)(&dir), "Up\0Down\0Left\0Right\0\0");

			// We can also use a std::vector<std::string> defined dynamically
			static int num_choices = 3;
			static std::vector<std::string> choices;
			static int idx_choice = 0;
			if (ImGui::InputInt("Num letters", &num_choices))
			{
				num_choices = std::max(1, std::min(26, num_choices));
			}
			if (num_choices != (int)choices.size())
			{
				choices.resize(num_choices);
				for (int i = 0; i < num_choices; ++i)
					choices[i] = std::string(1, 'A' + i);
				if (idx_choice >= num_choices)
					idx_choice = num_choices - 1;
			}
			ImGui::Combo("Letter", &idx_choice, choices);

			// Add a button
			if (ImGui::Button("Print Hello", ImVec2(-1, 0)))
			{
				std::cout << "Hello\n";
			}
		}
	};

	// Add additional windows via defining a Lambda expression with captures by reference([&])
	menu.callback_draw_custom_window = [&]()
	{
		// Define next window position + size
		ImGui::SetNextWindowPos(ImVec2(180.f * menu.menu_scaling(), 10), ImGuiSetCond_FirstUseEver);
		ImGui::SetNextWindowSize(ImVec2(300, 350), ImGuiSetCond_FirstUseEver);
		ImGui::Begin( "MyProperties", nullptr, ImGuiWindowFlags_NoSavedSettings );
		
		// point size
		// [event handle] if value changed
		if (ImGui::InputFloat("point_size", &g_myctx.point_size))
		{
			std::cout << "point_size changed\n";
			viewer.data().point_size = g_myctx.point_size;
		}

		// line width
		// [event handle] if value changed
		if(ImGui::InputFloat("line_width", &g_myctx.line_width))
		{
			std::cout << "line_width changed\n";
			viewer.data().line_width = g_myctx.line_width;
		}

		ImGui::SliderFloat("GaussianNoise", &g_myctx.GaussianNoise, 0, 0.2, "%.3f");
		ImGui::SliderInt("first k eigenvalues", &g_myctx.k, 3, 100);
        ImGui::SliderInt("number of iterations", &g_myctx.maxIter, 1, 500);
		//mode
		ImGui::SliderInt("Mode", &g_myctx.mode, 0,8);
        // select model
        ImGui::SliderInt("Model", &g_myctx.model, 0,5);
        //
        ImGui::InputFloat("lambda", &g_myctx.lambda, 0,0.001, "%.7f");

		//mode-text
		if (g_myctx.mode == 1) { 
			ImGui::Text("mode: uniform LPB : MEAN");
		}
		else if (g_myctx.mode == 2) {
			ImGui::Text("mode: cotan LPB : MEAN ");
		}
		else if (g_myctx.mode == 3){
			ImGui::Text("mode: cotan LPB : MEAN with igl functions (for comparison)");
		}
        else if (g_myctx.mode == 4){
            ImGui::Text("mode: Gauss Curvature");
        }
        else if (g_myctx.mode == 5){
            ImGui::Text("mode: Spectral meshes");
        }
		else if (g_myctx.mode == 6){
			ImGui::Text("mode: explicit smoothing");
		}
		else if (g_myctx.mode == 7){
			ImGui::Text("mode: implicit smoothing");
		}
		else if (g_myctx.mode == 8){
			ImGui::Text("mode: adding Gaussian noise");
		}
        else {
            ImGui::Text("mode: Resetting");
        }

        if (ImGui::Button("Apply")) {
        	std::cout << "Applying" << std::endl;
            g_myctx.reset_display(viewer);
        }

        if (g_myctx.model == 1) {
            ImGui::Text("model: camel");
        }
        else if (g_myctx.model == 2) {
            ImGui::Text("model: cow ");
        }
        else if (g_myctx.model == 3) {
            ImGui::Text("model: cube ");
        }
        else if (g_myctx.model == 4) {
            ImGui::Text("model: dragon ");
        }
		else if (g_myctx.model == 5) {
			ImGui::Text("model: cow manifold ");
		}
        else{
            ImGui::Text("model: bunny ");
        }


        ImGui::End();
	};


	// registered a event handler
	viewer.callback_key_down = &key_down;

	g_myctx.reset_display(viewer);

	// Call GUI
	viewer.launch();

}


void get_example_mesh(std::string const meshname , Eigen::MatrixXd & V, Eigen::MatrixXi & F, Eigen::MatrixXd & VN)
{
    
    
    std::vector<const char *> cands{
        "../../data/",
        "../../../data/",
        "../../../../data/",
        "../../../../../data/" };
    
    bool found = false;
    for (const auto & val : cands)
    {
        if ( igl::file_exists(val+ meshname) )
        {
            std::cout << "loading example mesh from:" << val+ meshname << "\n";
            
            //if (igl::readOFF(val+ meshname, V,F)) {
            if (igl::readOBJ(val+ meshname, V,F)) {
                igl::per_vertex_normals(V, F, VN);
                found = 1;
                break;
            }
            else {
                std::cout << "file loading failed " << cands[0] + meshname << "\n";
            }
        }
    }
    
    if (!found) {
        std::cout << "cannot locate "<<cands[0]+ meshname <<"\n";
        exit(1);
    }
    
}
