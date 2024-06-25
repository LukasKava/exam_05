#pragma once
#include <map>
#include "ATarget.hpp"

class TargetGenerator {
	private:
		TargetGenerator(const TargetGenerator &other);
		TargetGenerator	&operator=(const TargetGenerator &other);
		std::map<std::string, ATarget *> _targets;
	public:
		TargetGenerator();
		~TargetGenerator();
		void	learnTargetType(ATarget *target);
		void	forgetTargetType(const std::string &type);
		ATarget	*createTarget(const std::string &type);
};