#pragma once
#ifndef NEIGHBOURS_H
#define NEIGHBOURS_H

#include "Core_Defines.h"
#include "Geometry.hpp"

#include <vector>
#include <memory>

namespace Engine
{
	namespace Neighbours
	{
		// creates Neighbours
		void Create_Neighbours(const Data::Geometry & geometry, const std::vector<bool> & boundary_conditions,
			const int n_shells, std::vector<std::vector<int>> &n_spins_in_shell,
			std::vector<std::vector<std::vector<int>>> & neigh,
			std::vector<int> &n_4spin, int &max_n_4spin, std::vector<std::vector<std::vector<int>>> &neigh_4spin,
			std::vector<std::vector<std::vector<scalar>>> &dm_normal,
			std::vector<std::vector<int>> &segments, std::vector<std::vector<std::vector<scalar>>> &segments_pos);

		// calculates shell radii for every shell
		std::vector<scalar> Get_Shell_Radius(const Data::Geometry & geometry, const int n_shells);

		// calculates array with maximal (for periodic bc) no of neighbours in each shell
		std::vector<int> Get_MaxNumber_NInShell(const Data::Geometry & geometry, const int n_shells, const std::vector<scalar> & shell_radius,
			std::vector<std::vector<scalar>> boundary_vectors, const bool borderOnly);

		// calculates the neighbours within all the shells
		void Get_Neighbours_in_Shells(const Data::Geometry & geometry, const int n_shells, const std::vector<scalar> & shell_radius,
			const std::vector<std::vector<scalar>> &boundary_vectors, std::vector<std::vector<int>> &n_spins_in_shell,
			std::vector<std::vector<std::vector<int>>> & neigh, std::vector<std::vector<std::vector<std::vector<scalar>>>> & neigh_pos, const bool borderOnly);

		// calculates the 4Spin Neighbours
		void Create_Neighbours_4Spin(const int nos, const int n_shells, const std::vector<std::vector<std::vector<int>>> & neigh, const std::vector<std::vector<int>> &n_spins_in_shell,
			const int &max_n_4spin, std::vector<int> &n_4spin, std::vector<std::vector<std::vector<int>>> &neigh_4spin);

		// calculates the Bulk DMI vectors
		void Create_DM_Norm_Vectors_Bulk(const int nos, const std::vector<scalar> &spin_pos, const int number_b_vectors,
			const std::vector<std::vector<scalar>> &boundary_vectors, const int n_shells, const std::vector<std::vector<int>> &n_spins_in_shell,
			const std::vector<std::vector<std::vector<int>>> & neigh, std::vector<std::vector<std::vector<std::vector<scalar>>>> & neigh_pos,
			const int max_ndm, std::vector<std::vector<std::vector<scalar>>> &dm_normal);

		// calculates the surface DMI vectors
		void Create_DM_Norm_Vectors_Surface(const int nos, const std::vector<scalar> &spin_pos, const int number_b_vectors,
			const std::vector<std::vector<scalar>> &boundary_vectors, const int n_shells, const std::vector<std::vector<int>> &n_spins_in_shell,
			const std::vector<std::vector<std::vector<int>>> & neigh, std::vector<std::vector<std::vector<std::vector<scalar>>>> & neigh_pos,
			const int max_ndm, std::vector<std::vector<std::vector<scalar>>> &dm_normal);

		// prints DMI vectors to file
		void DM_Norm_Vectors_To_File(const int nos, const int n_shells, const std::vector<std::vector<int>> &n_spins_in_shell, const std::vector<std::vector<std::vector<int>>> & neigh,
			const std::vector<std::vector<std::vector<scalar>>> &dm_normal);

		// calculates the segments
		void Create_Segments(const Data::Geometry & geometry, int n_shells, const int nos,
			const std::vector<scalar> &spin_pos, const std::vector<std::vector<int>> &n_spins_in_shell, 
			const std::vector<std::vector<std::vector<int>>> & neigh, std::vector<std::vector<std::vector<std::vector<scalar>>>> & neigh_pos,
			std::vector<std::vector<int>> &segments, std::vector<std::vector<std::vector<scalar>>> &segments_pos);

		void Create_Dipole_Pairs(const Data::Geometry & geometry, scalar dd_radius,
		std::vector<std::vector<std::vector<int>>> & DD_indices, std::vector<std::vector<scalar>> & DD_magnitude, std::vector<std::vector<std::vector<scalar>>> & DD_normal);

		void Create_Dipole_Neighbours(const Data::Geometry & geometry, std::vector<bool> boundary_conditions,
			const scalar dd_radius, std::vector<std::vector<int>> & dd_neigh, std::vector<std::vector<std::vector<scalar>>>& dd_neigh_pos,
			std::vector<std::vector<std::vector<scalar>>> & dd_normal, std::vector<std::vector<scalar>> & dd_distance);

		// Creates the boundary vectors for given boundary_conditions and geometry
		std::vector<std::vector<scalar>> Get_Boundary_Vectors(const Data::Geometry & geometry, const std::vector<bool> & boundary_conditions);

		// Convert a list of neighbour shells into a list of pairs.
		void Create_DD_Pairs_from_Neighbours(const Data::Geometry & geometry, const std::vector<std::vector<int>> & dd_neighbours,
			const std::vector<std::vector<std::vector<scalar>>> & dd_neighbours_positions, const std::vector<std::vector<scalar>> & dd_distance,
			const std::vector<std::vector<std::vector<scalar>>> & dd_normal, std::vector<std::vector<std::vector<int>>> & DD_indices,
			std::vector<std::vector<scalar>> & DD_magnitude, std::vector<std::vector<std::vector<scalar>>> & DD_normal);
	};// end namespace Neighbours
}// end namespace Engine
#endif