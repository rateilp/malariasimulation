
#include <Rcpp.h>
#include "Random.h"

//[[Rcpp::export]]
void random_seed(size_t seed) {
    Random::get_instance().seed(seed);
}

//[[Rcpp::export]]
std::vector<size_t> bernoulli_multi_p_cpp(const std::vector<double> p) {
    auto values = Random::get_instance().bernoulli_multi_p(p);
    for (auto i = 0u; i < values.size(); ++i) {
        values[i]++;
    }
    return values;
}

//[[Rcpp::export(rng = false)]]
Rcpp::IntegerVector fast_weighted_sample(
    size_t size,
    std::vector<double> probs
    ) {
    Rcpp::IntegerVector values(size);
    Random::get_instance().prop_sample_bucket(
        size,
        probs,
        INTEGER(values)
    );
    values = values + 1;
    return values;
}
