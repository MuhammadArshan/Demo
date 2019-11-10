// csv_reader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{

	ifstream path("C:\\Users\\Arshan\\Desktop\\Master Thesis\\Main_ART_DataSet.csv");

	if (!path.is_open()) std::cout << "Error Openning File!" << '\n';

	//String for 'CSV-file'
	string Frame;
	string Name;
	string X;
	string Y;
	string Z;

	//Bone Names and X,Y,Z coordinates of Bones
	std::vector<string> Bone_Name;
	std::vector<float> Bones_X;
	std::vector<float> Bones_Y;
	std::vector<float> Bones_Z;

	//'Frame_input' for extract that frame X,Y,Z coordinates
	string Frame_Input;
	//For 'break' the while loop
	int a = 0;

	//UpperBody Bone Memory (Pelvis(Parent), LowerLumbarSpine, UpperLumbarSpine, LowerThoracicSpine, UpperThoracicSpine)
	std::vector<string> UpperBody_Name;
	std::vector<float> UpperBody_X;
	std::vector<float> UpperBody_Y;
	std::vector<float> UpperBody_Z;

	//HeadBones Memory (UpperThoracicSpine(Parent), Neck, Head)
	std::vector<string> HeadBones_Name;
	std::vector<float>  HeadBones_X;
	std::vector<float>  HeadBones_Y;
	std::vector<float>  HeadBones_Z;

	//LeftUpperLimb Memory (UpperThoracicSpine(Parent), LeftShoulder, LeftUpperArm, LeftLowerArm, LeftHand)
	std::vector<string> LeftUpperLimb_Name;
	std::vector<float>  LeftUpperLimb_X;
	std::vector<float>  LeftUpperLimb_Y;
	std::vector<float>  LeftUpperLimb_Z;

	//RightUpperLimb Memory (UpperThoracicSpine(Parent), RightShoulder, RightUpperArm, RightLowerArm, RightHand)
	std::vector<string> RightUpperLimb_Name;
	std::vector<float>  RightUpperLimb_X;
	std::vector<float>  RightUpperLimb_Y;
	std::vector<float>  RightUpperLimb_Z;

	//LeftLowerLimb Memory (Pelvis(Parent), LeftUpperLeg, LeftLowerLeg, LeftFoot)
	std::vector<string> LeftLowerLimb_Name;
	std::vector<float> LeftLowerLimb_X;
	std::vector<float> LeftLowerLimb_Y;
	std::vector<float> LeftLowerLimb_Z;

	//RightLowerLimb Memory (Pelvis(Parent), RightUpperLeg, RightLowerLeg, RightFoot)
	std::vector<string> RightLowerLimb_Name;
	std::vector<float> RightLowerLimb_X;
	std::vector<float> RightLowerLimb_Y;
	std::vector<float> RightLowerLimb_Z;

	//Enter Frame Number
	cout << "Enter Frame Number\n";
	cin >> Frame_Input;

	while (path.good())
	{
		getline(path, Frame, ',');
		getline(path, Name, ',');
		getline(path, X, ',');
		getline(path, Y, ',');
		getline(path, Z, '\n');

		if (Frame_Input == Frame)
		{
			/*std::cout << "Bone Name: " << Name <<", X: " << X << '\n';*/
			Bone_Name.push_back(Name);
			Bones_X.push_back(std::stof(X));
			Bones_Y.push_back(std::stof(Y));
			Bones_Z.push_back(std::stof(Z));
			a = a + 1;
			if (a >= 21)
			{
				break;
			}
		}
	}

	/*for (size_t i = 0; i < Bone_Name.size(); i++)
	{
	std::cout << Bone_Name[i] << " : (" << Bones_X[i] << "," << Bones_Y[i] << "," << Bones_Z[i] << ")" << '\n';
	}*/

	//Arrange X,Y,Z Coordinates according to Skeleton
	//UpperBody Bones
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << Bone_Name[i] << " : (" << Bones_X[i] << "," << Bones_Y[i] << "," << Bones_Z[i] << ")" << '\n';
		UpperBody_X.push_back(Bones_X[i]);
		UpperBody_Y.push_back(Bones_Y[i]);
		UpperBody_Z.push_back(Bones_Z[i]);
	}
	for (size_t i = 5; i < 7; i++)
	{
		std::cout << Bone_Name[i] << " : (" << Bones_X[i] << "," << Bones_Y[i] << "," << Bones_Z[i] << ")" << '\n';
	}
	//
	for (size_t i = 7; i < 11; i++)
	{
		std::cout << Bone_Name[i] << " : (" << Bones_X[i] << "," << Bones_Y[i] << "," << Bones_Z[i] << ")" << '\n';
	}
	for (size_t i = 11; i < 15; i++)
	{
		std::cout << Bone_Name[i] << " : (" << Bones_X[i] << "," << Bones_Y[i] << "," << Bones_Z[i] << ")" << '\n';
	}
	for (size_t i = 15; i < 18; i++)
	{
		std::cout << Bone_Name[i] << " : (" << Bones_X[i] << "," << Bones_Y[i] << "," << Bones_Z[i] << ")" << '\n';
	}
	for (size_t i = 18; i < 21; i++)
	{
		std::cout << Bone_Name[i] << " : (" << Bones_X[i] << "," << Bones_Y[i] << "," << Bones_Z[i] << ")" << '\n';
	}
	path.close();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
